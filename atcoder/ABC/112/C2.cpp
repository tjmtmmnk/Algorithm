//AC
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point {
    int x;
    int y;
    int h;
};

int main() {
    int n, aval_h;
    cin >> n;
    vector<Point> points(105);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].h;
        if (points[i].h > 0) {
            aval_h = i;
        }
    }

    for (int px = 0; px < 101; ++px) {
        for (int py = 0; py < 101; ++py) {
            int h = points[aval_h].h + abs(points[aval_h].x - px) + abs(points[aval_h].y - py);
            bool is_ok = true;
            for (int i = 0; i < n; ++i) {
                int dist = max(h - abs(points[i].x - px) - abs(points[i].y - py),0);
                if (dist != points[i].h) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) {
                cout << px << " " << py << " " << h << endl;
            }
        }
    }
}