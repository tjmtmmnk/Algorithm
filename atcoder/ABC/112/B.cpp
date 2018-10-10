//AC
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)
#define repe(i, s, n) for(int i = s;i<=n;i++)

typedef pair<int, int> P;

bool pairCompare(const P &firstElof, const P &secondElof) {
    return firstElof.first < secondElof.first;
}

int main(void) {
    int N, T;
    vector<pair<int, int >> cost;
    cin >> N >> T;
    rep(i, 0, N) {
        P inp;
        cin >> inp.first >> inp.second;
        if (inp.second <= T) {
            cost.push_back(inp);
        }
    }

    if (cost.empty()) {
        cout << "TLE" << endl;
    } else {
        sort(cost.begin(), cost.end(), pairCompare);
        cout << cost.front().first << endl;
    }
}