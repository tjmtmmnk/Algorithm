//AC
#include <iostream>

using namespace std;

typedef enum ArrowState {
    RIGHT,
    LEFT,
    UP,
    DOWN
} Arrow;

void Move(int &dx, int &dy, Arrow state) {
    switch (state) {
        case RIGHT:
            dx += 1;
            break;
        case LEFT:
            dx -= 1;
            break;
        case UP:
            dy -= 1;
            break;
        case DOWN:
            dy += 1;
            break;
    }
}

void getArrowState(Arrow &state, char mirror) {
    switch (state) {
        case RIGHT: {
            switch (mirror) {
                case '\\':
                    state = DOWN;
                    break;
                case '/':
                    state = UP;
                    break;
            }
            break;
        }
        case LEFT: {
            switch (mirror) {
                case '\\':
                    state = UP;
                    break;
                case '/':
                    state = DOWN;
                    break;
            }
            break;
        }
        case UP: {
            switch (mirror) {
                case '\\':
                    state = LEFT;
                    break;
                case '/':
                    state = RIGHT;
                    break;
            }
            break;
        }
        case DOWN: {
            switch (mirror) {
                case '\\':
                    state = RIGHT;
                    break;
                case '/':
                    state = LEFT;
                    break;
            }
            break;
        }
    }
}

int main() {
    int w, h;
    cin >> h >> w;

    char box[120][120];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> box[i][j];
        }
    }

    int now_w = 0, now_h = 0;
    int count = 0;
    Arrow arrow = RIGHT;

    while (1) {
        getArrowState(arrow, box[now_h][now_w]);
        Move(now_w, now_h, arrow);
        count++;
        if (now_w >= w || now_h >= h) {
            break;
        }
        if (now_w < 0 || now_h < 0) {
            break;
        }
    }

    cout << count << endl;
}