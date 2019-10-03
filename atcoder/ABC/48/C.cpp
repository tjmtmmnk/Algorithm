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
 * 隣り合う箱A,A+1のキャンディの総和がx以下なので
 * Aをx以下かつなるべく使うようにする(xより大きければxに抑え込む)と、
 * A+1で A+1 = x-A が成立する(∵ A <= x)
 * これを繰り返すと全体で最小の操作で済む
 * こうして得られた必要なキャンディの配列と元のキャンディの配列とを比較した差分が求める値
 */
int main(void) {
    int n, x;
    cin >> n >> x;
    vi a(n, 0);
    vi origin(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        origin[i] = a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > x) {
            int diff = a[i] - x;
            a[i] = x;
        }

        if (a[i] + a[i + 1] > x) {
            int diff = x - a[i];
            a[i + 1] = diff;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (ll) (origin[i] -a[i]);
    }
    cout << ans << endl;
}