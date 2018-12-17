//AC time:21ms memory:6528KB
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int mx[4] = {-1, 0, 0, 1};
int my[4] = {0, 1, -1, 0};

int H, W;
char street[550][550];
bool is_reached[550][550];

bool canReach(int x, int y) {
    if (x < 0 || y < 0 || x >= W || y >= H || street[y][x] == '#') { return false; }

    if (is_reached[y][x]) { return false; }

    if (street[y][x] == 'g') {
        return true;
    }

    is_reached[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int dx = x + mx[i];
        int dy = y + my[i];
        if (canReach(dx, dy)) { return true; }
    }
    return false;
}
int main() {
    int s_x, s_y;
    cin >> H >> W;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            cin >> street[h][w];
            if (street[h][w] == 's') {
                s_x = w;
                s_y = h;
            }
        }
    }

    if (canReach(s_x, s_y)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

