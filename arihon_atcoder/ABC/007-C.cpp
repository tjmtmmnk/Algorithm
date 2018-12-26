#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

int R, C;
int sx, sy, gx, gy;
char street[100][100];
int dist[100][100];
queue<pair<int, int>> q;

int main(void) {
    cin >> R >> C >> sy >> sx >> gy >> gx;
    sx -= 1;
    sy -= 1;
    gx -= 1;
    gy -= 1;
    int cnt = 0;

    pair<int, int> start;
    start.first = sx;
    start.second = sy;
    q.push(start);

    rep(r, 0, R) {
        rep(c, 0, C) {
            cin >> street[r][c];
            dist[r][c] = 30000;
        }
    }

    dist[sy][sx] = 0;

    while (!q.empty()) {
        const int x = q.front().first;
        const int y = q.front().second;
        rep(i, 0, 4) {
            int dx = x + mx[i];
            int dy = y + my[i];
            if (dx >= 0 && dx < C && dy >= 0 && dy < R && dist[dy][dx] == 30000) {
                if (street[dy][dx] == '.') {
                    int prev = dist[y][x];
                    dist[dy][dx] = min(dist[dy][dx], ++prev);
                    if (dx == gx && dy == gy) {
                        cout << dist[dy][dx] << endl;
                        return 0;
                    }
                    pair<int, int> temp;
                    temp.first = dx;
                    temp.second = dy;
                    q.push(temp);
                }
            }
        }
        q.pop();
    }
}