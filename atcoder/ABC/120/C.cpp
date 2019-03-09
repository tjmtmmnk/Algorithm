#include<iostream>
#include<vector>
#include<algorithm>
#include <set>

using namespace std;

string s;

int main(void) {
    cin >> s;
    int zero = 0, one = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            zero++;
        } else {
            one++;
        }
    }
    cout << min(zero, one) * 2 << endl;
}