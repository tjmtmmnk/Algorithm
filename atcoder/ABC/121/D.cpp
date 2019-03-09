#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long calc(long long x) {
    long long cnt = (x + 1) / 2;
    long long ans = cnt % 2;
    if (x % 2 == 0) { ans ^= x; }
    return ans;
}
int main(void) {
    long long int a, b;
    cin >> a >> b;

    long long ans = calc(a - 1) ^calc(b);

    cout << ans << endl;
}