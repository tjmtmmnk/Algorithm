//WA 問題1~7までAC
#include<iostream>
#include <vector>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

typedef struct point {
    int x;
    int y;
    int h;
} Point;

int main(void) {
    int N;
    vector<Point> points;
    Point tgt;
    cin >> N;
    rep(i, 0, N) {
        Point p;
        cin >> p.x >> p.y >> p.h;
        points.push_back(p);
    }

    const Point fp = points.front();
    tgt = fp;

    rep(i, 1, points.size()) {
        int diff_x = points[i].x - fp.x;
        int diff_y = points[i].y - fp.y;
        int diff_h = points[i].h - fp.h;

        if (diff_h > 0 && diff_x != 0) {
            tgt.x += diff_x;
            tgt.h += diff_h;

        } else if (diff_h > 0 && diff_y != 0) {
            tgt.y += diff_y;
            tgt.h += diff_h;
        }

        if (diff_h == 0 && diff_x != 0 && diff_x % 2 == 0) {
            tgt.x += (diff_x / 2);
            tgt.h++;
        } else if (diff_h == 0 && diff_y != 0 && diff_y % 2 == 0) {
            tgt.y += (diff_y / 2);
            tgt.h++;
        }
    }

    cout << tgt.x << " " << tgt.y << " " << tgt.h << endl;
}