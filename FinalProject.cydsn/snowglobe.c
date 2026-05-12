#include <project.h>
#include <stdlib.h>
#include "tft.h"
#include "snowglobe.h"

#define PARTICLES_PER_SCREEN  20
#define PARTICLE_PX           5                     // particle is PARTICLE_PX * PARTICLE_PX pixels

// fixed point in Q4
#define Q                     4
#define ONE_PX                (1 << Q)

// physics
#define MAX_SPEED             (8 * ONE_PX)          // terminal speed in either axis
#define DAMP_NUM              15                    // velocity *= 15/16 each tick as drag
#define DAMP_DEN              16
#define SHAKE_KICK            (20 * ONE_PX)         // shake gives random vel in +/- SHAKE_KICK
#define WALL_BOUNCE_NUM       1                     // bounce keeps 1/2 of speed into wall
#define WALL_BOUNCE_DEN       2
#define SHAKE_THRESHOLD       2000                  // threshold for difference from 1g for applying change in velocity due to shaking (1g = 16384)
#define GRAVITY_SHIFT         13                    // by default for the IMU, 1g = 2^13 --> divide to get # of g's

#define BG_COLOR              0x0000   // black
#define SNOW_COLOR            0xFFFF   // white


// vars to convert from accelerometer data (ax, ay, az) into a 2D gravity vector for each screen
static const uint8_t gx_use_ay[NUM_SCREENS] = { 0, 1, 0, 1 };
static const int8_t  gx_sign  [NUM_SCREENS] = {-1,-1,+1,+1 };           // gx is horizontal acceleration and can be either ax or ay
static const int8_t  gy_sign  [NUM_SCREENS] = {+1,+1,+1,+1 };           // gy is vertical acceleration and is always az


typedef struct {
    int16_t x, y;        // position in Q4 sub-pixels
    int16_t vx, vy;      // velocity in Q4 sub-pixels per tick
    int16_t prev_px;     // last drawn pixel position
    int16_t prev_py;
} Particle;

static Particle particles[NUM_SCREENS][PARTICLES_PER_SCREEN];
static int16_t  prev_ax = 0, prev_ay = 0, prev_az = 0;
static uint8_t  initialized = 0;


static int16_t randPM(int16_t range)
{
    if (range <= 0) return 0;
    return (int16_t)((rand() % (2 * range + 1)) - range);
}

static int16_t randIn(int16_t lo, int16_t hi)
{
    if (hi <= lo) return lo;
    return (int16_t)(lo + (rand() % (hi - lo + 1)));
}

static int16_t constrainInt16(int16_t v, int16_t lo, int16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

//==============================================================
// initialization for snowglobe mode
//==============================================================
void snowglobeInit(void)
{
    uint8_t d;
    uint8_t i;

    for (d = 0; d < NUM_SCREENS; d++) {
        clearScreen(d, BG_COLOR);
    }

    for (d = 0; d < NUM_SCREENS; d++) {
        for (i = 0; i < PARTICLES_PER_SCREEN; i++) {
            int16_t px = randIn(0, SCREEN_WIDTH  - PARTICLE_PX - 1);
            int16_t py = randIn(0, SCREEN_HEIGHT - PARTICLE_PX - 1);

            particles[d][i].x  = (int16_t)(px << Q);
            particles[d][i].y  = (int16_t)(py << Q);
            particles[d][i].vx = 0;
            particles[d][i].vy = 0;
            particles[d][i].prev_px = px;
            particles[d][i].prev_py = py;

            drawRect(d, px, px + PARTICLE_PX - 1,
                        py, py + PARTICLE_PX - 1, SNOW_COLOR);
        }
    }

    prev_ax = 0;
    prev_ay = 0;
    prev_az = 0;
    initialized = 1;
}

//==============================================================
// update screen while in snowglobe mode
//==============================================================
void snowglobeUpdate(int16 ax, int16 ay, int16 az)
{
    if (!initialized) snowglobeInit();

    // absolute value of difference in acceleration for shake detection
    int32_t delta = labs((int32_t)ax - prev_ax)
                  + labs((int32_t)ay - prev_ay)
                  + labs((int32_t)az - prev_az);
    prev_ax = ax;
    prev_ay = ay;
    prev_az = az;
    uint8_t shaken = (delta > SHAKE_THRESHOLD);

    const int16_t max_x_q = (int16_t)((SCREEN_WIDTH  - PARTICLE_PX) << Q);
    const int16_t max_y_q = (int16_t)((SCREEN_HEIGHT - PARTICLE_PX) << Q);

    uint8_t d, i;
    for (d = 0; d < NUM_SCREENS; d++) {         // for each screen, compute 2d gravity vector

        int16_t horiz = gx_use_ay[d] ? ay : ax;
        int16_t gx_step = (int16_t)(((int32_t)horiz * gx_sign[d]) >> GRAVITY_SHIFT);
        int16_t gy_step = (int16_t)(((int32_t)az    * gy_sign[d]) >> GRAVITY_SHIFT);

        for (i = 0; i < PARTICLES_PER_SCREEN; i++) {
            Particle *p = &particles[d][i];

            // shaken --> randomize this particle's velocity in both axes
            if (shaken) {
                p->vx = randPM(SHAKE_KICK);
                p->vy = randPM(SHAKE_KICK);
            }

            // apply gravity to adjust velocity
            p->vx = (int16_t)(p->vx + gx_step);
            p->vy = (int16_t)(p->vy + gy_step);

            // apply damping
            p->vx = (int16_t)(((int32_t)p->vx * DAMP_NUM) / DAMP_DEN);
            p->vy = (int16_t)(((int32_t)p->vy * DAMP_NUM) / DAMP_DEN);

            // cap speeds to prevent particles moving too much
            p->vx = constrainInt16(p->vx, -1 * MAX_SPEED, MAX_SPEED);
            p->vy = constrainInt16(p->vy, -1 * MAX_SPEED, MAX_SPEED);

            // move the particles
            p->x = (int16_t)(p->x + p->vx);
            p->y = (int16_t)(p->y + p->vy);

            // bounce off walls
            if (p->x < 0) {
                p->x  = 0;
                p->vx = (int16_t)(-((int32_t)p->vx * WALL_BOUNCE_NUM) / WALL_BOUNCE_DEN);
            } else if (p->x > max_x_q) {
                p->x  = max_x_q;
                p->vx = (int16_t)(-((int32_t)p->vx * WALL_BOUNCE_NUM) / WALL_BOUNCE_DEN);
            }
            if (p->y < 0) {
                p->y  = 0;
                p->vy = (int16_t)(-((int32_t)p->vy * WALL_BOUNCE_NUM) / WALL_BOUNCE_DEN);
            } else if (p->y > max_y_q) {
                p->y  = max_y_q;
                p->vy = (int16_t)(-((int32_t)p->vy * WALL_BOUNCE_NUM) / WALL_BOUNCE_DEN);
            }

            int16_t new_px = (int16_t)(p->x >> Q);
            int16_t new_py = (int16_t)(p->y >> Q);

            // skip redraw if same position
            if (new_px == p->prev_px && new_py == p->prev_py) continue;

            // otherwise redraw
            drawRect(d, p->prev_px, p->prev_px + PARTICLE_PX - 1,
                        p->prev_py, p->prev_py + PARTICLE_PX - 1,
                        BG_COLOR);
            drawRect(d, new_px, new_px + PARTICLE_PX - 1,
                        new_py, new_py + PARTICLE_PX - 1,
                        SNOW_COLOR);

            p->prev_px = new_px;
            p->prev_py = new_py;
        }
    }
}