//AC
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    string inp;
    bool is_yes;
    cin >> inp;
    sort(inp.begin(), inp.end());
    rep(i, 0, inp.length() - 1) {
        if (inp[i] == inp[i + 1]) {
            is_yes = false;
            break;
        } else {
            is_yes = true;
        }
    }
    if (is_yes) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}