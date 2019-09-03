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

/*
 * 考え方
 * 水と塩は F以内に収まらなければならないので O(F^2)=O(10^6)で収まる
 * あとは全探索して条件に当てはまるものの中で濃度が最大の水と塩の値を求めればよい
*/
int main(void) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<pair<pii, float>> densities;
    int waterA = 0;
    int waterB = 0;
    int saltC = 0;
    int saltD = 0;
    for (int wa = 0; wa <= 30; ++wa) {
        waterA = 100 * a * wa;
        for (int wb = 0; wb <= 30; ++wb) {
            waterB = 100 * b * wb;
            for (int sc = 0; sc <= 100; ++sc) {
                saltC = c * sc;
                for (int sd = 0; sd <= 100; ++sd) {
                    saltD = d * sd;
                    int water = waterA + waterB;
                    int salt = saltC + saltD;
                    if (water + salt <= f && salt <= water * e / 100) {
                        if (water + salt > 0) {
                            float density = (float) (100 * salt) / (float) (water + salt);
                            densities.push_back(make_pair(make_pair(water + salt, salt), density));
                        }
                    }

                }
            }
        }
    }
    sort(densities.begin(), densities.end(), pairCompare<pii, float>);
    cout << densities[0].first.first << " " << densities[0].first.second << endl;
}