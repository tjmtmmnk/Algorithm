#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
static const ll maxLL = (ll) 1 << 62;
const ll MOD = 1000000007, INF = 1e18;

int main(void) {
    int n, p;
    cin >> n >> p;
    vi biscuits(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> biscuits[i];
    }
    bool is_exist_odd = false;
    for (auto biscuit : biscuits) {
        if (biscuit % 2 == 1) is_exist_odd = true;
    }
    if (is_exist_odd) {
        cout << (ll) pow(2, n - 1);
    } else {
        if (p % 2 == 0) {
            cout << (ll) pow(2, n);
        } else {
            cout << 0 << endl;
        }
    }
}