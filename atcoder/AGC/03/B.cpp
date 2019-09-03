#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

/*
 * 考え方
 * 0枚が含まれないときは結局は2つで1つのペアを作るということなので 総数/2 になる
 * 0枚が含まれるときはその両隣とペアは作れない
 * よって全体を見て行って0枚があればそれまでの総数/2を足していくという行為を最後まで繰り返せば答えが得られる
*/
int main(void) {
    int n;
    cin >> n;
    vll num_of_i(n);
    for (int i = 0; i < n; ++i) {
        cin >> num_of_i[i];
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += num_of_i[i];
        if (num_of_i[i] == 0 || i == n - 1) {
            ans += sum / 2LL;
            sum = 0;
        }
    }
    cout << ans << endl;
}