#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i > 0; --i) {
        if ((a % i == 0) && (b % i == 0)) { cnt++; }
        if (cnt == k) {
            cout << i << endl;
            break;
        }
    }
}
