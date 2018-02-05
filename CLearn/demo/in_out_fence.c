#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define sign(x) ((x)<0 ? -1 : 1)

typedef struct{
    float x;                  
    float y;
}Vector2f;  

bool Polygon_outside(const Vector2f P, const Vector2f V[], unsigned n)
{
    unsigned i, j;
    bool outside = true;
    for (i = 0, j = n-1; i < n; j = i++) {
        if ((V[i].y > P.y) == (V[j].y > P.y)) {
            continue;
        }   
        int32_t dx1, dx2, dy1, dy2;
        dx1 = P.x - V[i].x;
        dx2 = V[j].x - V[i].x;
        dy1 = P.y - V[i].y;
        dy2 = V[j].y - V[i].y;
        int8_t dx1s, dx2s, dy1s, dy2s, m1, m2;
        dx1s = sign(dx1);
        dx2s = sign(dx2);
        dy1s = sign(dy1);
        dy2s = sign(dy2);
        m1 = dx1s * dy2s;
        m2 = dx2s * dy1s;
        // we avoid the 64 bit multiplies if we can based on sign checks.
        if (dy2 < 0) {
            if (m1 > m2) {
                outside = !outside;
            } else if (m1 < m2) {
                continue;
            } else if ( dx1 * (int64_t)dy2 > dx2 * (int64_t)dy1 ) { 
                outside = !outside;
            }   
        } else {
            if (m1 < m2) {
                outside = !outside;
            } else if (m1 > m2) {
                continue;
            } else if ( dx1 * (int64_t)dy2 < dx2 * (int64_t)dy1 ) { 
                outside = !outside;
            }   
        }   
    }   
    return outside;
}


int main(void)
{
    Vector2f pos[4];
    Vector2f home;
    home.x = 0;
    home.y = 3;
    pos[0].x = -2;
    pos[0].y = 2;
    pos[1].x = 2;
    pos[1].y = 2;
    pos[2].x = 2;
    pos[2].y = -2;
    pos[3].x = -2;
    pos[3].y = -2;
    bool out = Polygon_outside(home,pos,4);
    printf("home is %d\n",out);
}
