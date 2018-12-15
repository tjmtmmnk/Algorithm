//AC
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)
using ll = long long int;

const float getDistance(const int x1, const int x2, const int y1, const int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(void) {
    int N;
    vector<pair<int, int>> point(100000);
    cin >> N;

    rep(i, 0, N) {
        cin >> point[i].first >> point[i].second;
    }

    float max_dist = getDistance(point[0].first, point[1].first, point[0].second, point[1].second);

    rep(i, 0, N) {
        rep(j, i, N) {
            float dist = getDistance(point[i].first, point[j].first, point[i].second, point[j].second);
            max_dist = max(max_dist, dist);
        }
    }
    printf("%.6f\n", max_dist);
}
