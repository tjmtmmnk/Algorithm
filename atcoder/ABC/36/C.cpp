#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T1, typename T2>
bool pairCompare(const pair<T1, T2> &firstElof, const pair<T1, T2> &secondElof) {
    return firstElof.second < secondElof.second;
}

#define rep(i, s, n) for(int i = s;i<n;i++)
#define repe(i, s, n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
static const ll maxLL = (ll) 1 << 62;
const ll MOD = 1000000007, INF = 1e18;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, ll>> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        a[i] = pair<int, ll>(i, t);
    }

    sort(a.begin(), a.end(), pairCompare<int, ll>);

    int atu = 0;
    int prev = a[0].se;
    for (int i = 0; i < n; ++i) {
        if (prev != a[i].se) {
            atu++;
            prev = a[i].se;
        }
        b[a[i].fi] = atu;
    }

    for (const auto e : b) {
        cout << e << endl;
    }
}