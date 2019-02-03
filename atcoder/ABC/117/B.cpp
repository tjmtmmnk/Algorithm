//AC time: 1ms, memory: 256KB
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    int n;
    vector<int> l(101, 0);

    cin >> n;
    rep(i, 0, n) { cin >> l[i]; }

    sort(l.begin(), l.end(), greater<int>());
    int max_l = l[0];
    int sum = 0;
    rep(i, 1, l.size()) {
        sum += l[i];
    }
    if (max_l < sum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
