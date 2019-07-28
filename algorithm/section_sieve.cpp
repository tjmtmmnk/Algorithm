#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

int main(void) {
    ll a, b;
    cin >> a >> b;

    bool *is_prime;
    bool *is_prime_small;

    is_prime = (bool *) malloc(1e12);
    is_prime_small = (bool *) malloc(1e6);

    for (int i = 0; (ll) i * i < b; ++i) {
        is_prime_small[i] = true;
    }

    for (int i = 0; i < b - a; ++i) {
        is_prime[i] = true;
    }

    for (int i = 2; (ll) i * i < b; ++i) {
        if (is_prime_small[i]) {
            for (int j = 2 * i; (ll) j * j < b; j += i) {
                is_prime_small[j] = false;
            }
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                is_prime[j - a] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < b - a; ++i) {
        if (is_prime[i]) cnt++;
    }

    cout << cnt << endl;
}