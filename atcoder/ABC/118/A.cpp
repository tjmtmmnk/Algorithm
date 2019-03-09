#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    int a, b;
    cin >> a >> b;
    if (b % a == 0) {
        cout << a + b << endl;
    } else {
        cout << b - a << endl;
    }
}
