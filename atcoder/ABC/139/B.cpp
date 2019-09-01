#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define pb push_back
#define fi first
#define se second
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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int tup = 1;
    while (1) {
        if (tup < b) {
            tup--;
            ans++;
        }
        tup += a;
        if (tup >= b) {
            break;
        }
    }

    cout << ans << endl;
}