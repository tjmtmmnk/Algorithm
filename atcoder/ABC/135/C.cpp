#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define rep(i, s, n) for(int i = s;i<n;i++)
#define repe(i, s, n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
static const ll maxLL = (ll) 1 << 62;
const ll MOD = 1000000007, INF = 1e18;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

template<typename T1, typename T2>
bool pairCompare(const pair<T1, T2> &firstElof, const pair<T1, T2> &secondElof) {
    return firstElof.second > secondElof.second;
}

int mapMaxValue(std::map<ll, int> m) {
    int max = 0;
    for (std::map<ll, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (max < it->second) max = it->second;
    }
    return max;
}

int main(void) {
    int n;
    cin >> n;
    vll monster(n + 1), brave(n);

    for (int i = 0; i < n + 1; ++i) {
        cin >> monster[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> brave[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll min_ii = min(monster[i], brave[i]);
        ans += min_ii;
        monster[i] -= min_ii;
        brave[i] -= min_ii;
        ll min_i_plus1 = min(monster[i + 1], brave[i]);
        ans += min_i_plus1;
        monster[i + 1] -= min_i_plus1;
        brave[i] -= min_i_plus1;
    }

    cout << ans << endl;
}