#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>

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

//pair比較
template<typename T1=int, typename T2=int>
bool pairCompare(const pair<T1, T2> &firstElof, const pair<T1, T2> &secondElof) {return firstElof.second > secondElof.second;}

//mapの最大値
int mapMaxValue(std::map<ll, int> m) {int max = 0;for (std::map<ll, int>::iterator it = m.begin(); it != m.end(); it++) {if (max < it->second) max = it->second;}return max;}

//素数判定
template<typename T=int>
bool isPrime(T n) {if (n < 2) { return false; }for (int i = 2; i * i <= n; i++) { if (n % i == 0) { return false; }}return true;}

//約数列挙
template<typename T=int>
vector<T> getDivisor(T n) {vector<T> v;for (T i = 1; i * i <= n; i++) {if (n % i == 0) {v.push_back(i);if (i != n / i) { v.push_back(n / i); }}}sort(v.begin(), v.end());return v;}

//最大公約数
template<typename T=int>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

//素因数分解
template<typename TP=int, typename TPOW=int>
vector<pair<TP, TPOW>> factorize(TP n) {vector<pair<TP, TPOW>> res;for (TP i = 2; i * i < n; ++i) {if (n % i) continue;res.emplace_back(i, 0);while (n % i == 0) {n /= i;res.back().second++;}}if (n != 1) res.emplace_back(n, 1);return res;}

int main(void) {
    ll a, b;
    cin >> a >> b;
    ll g = gcd<ll>(a, b);
    auto f = factorize<ll, int>(g);
    cout << f.size() + 1 << endl;
}