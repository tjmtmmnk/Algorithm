#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

/*
 * 考え方
 * X_i < X_{i+1} が成り立っているので左から徒歩かテレポーションか決めていく
 * 徒歩の場合は、 X_{i+1}-X_i が町と町の間の距離で1移動するごとにAの疲労がたまるので  (X_{i+1}-X_i)*A のコストがかかる
 * テレポーションの場合は移動距離に依らず Bのコストがかかる
 * この2つのコストのうち最初のコストを選び続けて移動すれば全体の移動コストは最小
 */
int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    vi x(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ll walk_cost = (ll) (x[i + 1] - x[i]) * a;
        if (walk_cost < (ll) b) {
            ans += walk_cost;
        } else {
            ans += (ll)b;
        }
    }
    cout << ans << endl;
}