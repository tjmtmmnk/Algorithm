#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef vector<int> vll;

map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
}

int main(void) {
    ll n;
    cin >> n;
    vll divisors(n);

    // nが約数d (n%d==0) を持ったとすると n/d も n の約数
    // n = d * n/d なので min(d, n/d) <= srqt(n)
    // よって O(sqrt(n))
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << "NO" << " " << i << endl;
            return 0;
        }
    }
}