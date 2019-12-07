#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;

typedef long long ll;

/*
 * 考え方
 * n,m <= 10^5 なので雑にやるとTLEになる
 * priority_queueを使うと根が最大値となるので最大値をO(1)で取り出せる
 * こうすると根を貪欲に最小にすればいいとわかる
 */
int main(void) {
    int n, m;
    cin >> n >> m;

    priority_queue<ll> prices;
    for (int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        prices.push(temp);
    }

    for (int i = 0; i < m; ++i) {
        ll max_price = prices.top();
        prices.pop();
        prices.push(max_price / 2LL);
    }

    ll ans = 0;
    while (!prices.empty()) {
        ans += prices.top();
        prices.pop();
    }
    cout << ans << endl;
}
