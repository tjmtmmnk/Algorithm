//AC time : 1ms, memory : 256KB
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

typedef pair<int, int> P;
const int INF = 30000;
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

    q.push(P(sx, sy));

    rep(r, 0, R) {
        rep(c, 0, C) {
            cin >> street[r][c];
            dist[r][c] = INF;
        }
    }

    dist[sy][sx] = 0;

    while (!q.empty()) {
        P p = q.front();
        q.pop();
        if (p.first == gx && p.second == gy) {
            cout << dist[gy][gx] << endl;
        }

        rep(i, 0, 4) {
            int dx = p.first + mx[i];
            int dy = p.second + my[i];

            if (dx >= 0 && dx < C && dy >= 0 && dy < R && dist[dy][dx] == INF && street[dy][dx] == '.') {
                q.push(P(dx, dy));
                dist[dy][dx] = dist[p.second][p.first] + 1;
            }
        }
    }
}