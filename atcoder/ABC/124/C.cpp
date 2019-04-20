#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s;

int solve() {
    int zero_one = 0;
    int one_zero = 0;
    for (int i = 0; i < s.length(); ++i) {
        if ((i % 2 == 0) && (s[i] != '0')) {
            zero_one++;
        } else if ((i % 2 == 1) && (s[i] != '1')) {
            zero_one++;
        }

        if ((i % 2 == 0) && (s[i] != '1')) {
            one_zero++;
        } else if ((i % 2 == 1) && (s[i] != '0')) {
            one_zero++;
        }
    }
    return (zero_one < one_zero) ? zero_one : one_zero;
}

int main(void) {
    cin >> s;
    int ans = solve();
    cout << ans << endl;
}
