#include <stdio.h>
#include <cstdlib>
#include <cmath>

struct Vector2 {
    int x;
    int y;
};

int shishagonyu(float x) {
    return (int) (x < 0.0 ? x - 0.5 : x + 0.5);
}

int main(void) {
    Vector2 v[4];
    Vector2 rv[4];
    Vector2 rrv[4];
    scanf("%d%d%d%d", &v[0].x, &v[0].y, &v[1].x, &v[1].y);

    float theta = atan2((float) (v[1].y - v[0].y), (float) (v[1].x - v[0].x));

    Vector2 temp = v[0];
    for (int j = 0; j < 2; ++j) {
        v[j].x -= temp.x;
        v[j].y -= temp.y;
    }

    for (int i = 0; i < 2; ++i) {
        rv[i].x = shishagonyu(v[i].x * cos(theta) + v[i].y * sin(theta));
        rv[i].y = shishagonyu(-v[i].x * sin(theta) + v[i].y * cos(theta));
    }

    int l = abs(rv[1].x - rv[0].x);

    rv[2].x = rv[1].x;
    rv[3].x = rv[0].x;
    rv[2].y = rv[3].y = rv[1].y + l;

    for (int i = 0; i < 4; ++i) {
        rrv[i].x = shishagonyu(rv[i].x * cos(theta) - rv[i].y * sin(theta));
        rrv[i].y = shishagonyu(rv[i].x * sin(theta) + rv[i].y * cos(theta));
    }

    for (int j = 0; j < 4; ++j) {
        rrv[j].x += temp.x;
        rrv[j].y += temp.y;
    }
    printf("%d %d %d %d\n", rrv[2].x, rrv[2].y, rrv[3].x, rrv[3].y);
}
