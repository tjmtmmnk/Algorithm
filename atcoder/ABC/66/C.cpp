#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <cmath>

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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mid = n / 2;
    vi ans;
    if (n % 2 == 0) {
        for (int i = mid; i > 0; --i) {
            ans.push_back(a[2 * i - 1]);
        }
        ans.push_back(a[0]);
        for (int i = 1; i <= mid - 1; ++i) {
            ans.push_back(a[2 * i]);
        }
    } else {
        for (int i = mid; i > 0; --i) {
            ans.push_back(a[2 * i]);
        }
        ans.push_back(a[0]);
        for (int i = 1; i <= mid; ++i) {
            ans.push_back(a[2 * i - 1]);
        }
    }
    for (const auto e : ans) {
        cout << e << " ";
    }
    cout << endl;
}
