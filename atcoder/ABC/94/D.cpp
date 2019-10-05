#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

/*
 * 考え方
 * 明らかに nCr のnが最大である必要がある
 * ただ組み合わせの計算量は爆発するので計算したくない
 * 性質に注目すると n/2 に最も近い r を選べば最大となると予想して実装した
 * 証明は解説pdfに書いてあった
*/
int main(void) {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());

    double mid = a[0] / 2.0;

    double prev = 999999999.0f;
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        double diff = abs(a[i] - mid);
        if (diff < prev) {
            ans = a[i];
        }
        prev = diff;
    }
    cout << a[0] << " " << ans << endl;

}
