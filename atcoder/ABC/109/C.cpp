#include <iostream>
#include <vector>

using namespace std;
typedef vector<pair<int, bool>> P;

int main(void) {
    int n, X, D;
    cin >> n >> X;
    vector<int> x(n);
    P pairs(n);

    for (int i = 0; i < n; ++i) {
        int inp;
        cin >> inp;
        x.push_back(inp);
    }


    for (D = 1; D < X - *min_element(x.begin(), x.end()); D++) {
        int px = X + D;
        int mx = X - D;
        if (find(x.begin(), x.end(), px) != x.end()) {
            X = px;
            pair<int, bool> p(px, true);
            pairs.push_back(p);
        } else if (find(x.begin(), x.end(), mx) != x.end()) {
            X = mx;
            pair<int, bool> p(mx, true);
            pairs.push_back(p);
        } else {
            X = px;
            pair<int, bool> p(px, false);
            pairs.push_back(p);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << pairs[i].first << "\t bool : " << pairs[i].second << endl;
    }
}