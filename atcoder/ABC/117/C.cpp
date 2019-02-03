//AC time: 43ms, memory: 1400KB
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <queue>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    int n, m;
    vector<int> x;
    priority_queue<int> diff;

    cin >> n >> m;
    n--;
    rep(i, 0, m) {
        int temp;
        cin >> temp;
        x.push_back(temp);
    }

    if ((n >= m) || (m == 1)) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());

    rep(i, 0, m - 1) {
        diff.push(x[i + 1] - x[i]);
    }

    rep(i, 0, n) {
        diff.pop();
    }

    long long int sum = 0;
    while (!diff.empty()) {
        sum += diff.top();
        diff.pop();
    }
    cout << sum << endl;
    return 0;
}
