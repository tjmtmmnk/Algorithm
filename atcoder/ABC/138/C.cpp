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

/*
 * 考え方
 * a, b, cを考えたときに順番に新しい具材を作っていくとすると
 * (a+b)/2 + c = a+b+2c/4 と c の加重が高くなる
 * なので昇順ソートして小さいものから具材を作っていくと最大値を取る
*/

int main(void) {
    int n;
    cin >> n;
    vi value(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    sort(value.begin(), value.end());

    float prev_value = (value[0] + value[1]) / 2.0f;
    float max_value = prev_value;

    for (int i = 2; i < n; ++i) {
        max_value = (prev_value + value[i]) / 2.0f;
        prev_value = max_value;
    }

    cout << max_value << endl;
}
