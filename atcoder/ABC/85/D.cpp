#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>

using namespace std;
typedef vector<int> vi;

/*
 * 考え方
 * まずa,bの値を降順でもソート
 * aが何度も使えてbが一度だけ使えるので最小の攻撃にするには明らかにa[0]を何度も使ったほうがいい
 * ただbがa[0]以上のときはbを使ったほうがいい
 * よってなるべくbを使って使えるbがなくなったらa[0]を使うようにする
 * H <= 10^9 なので10^9をそのまま引き算するようにすると間に合わない
 * よってHを割り算して0になるようだったらそれで終了して、0にならなければHから引くようにすることを繰り返せば良い
*/
int main(void) {
    int n, hp;
    cin >> n >> hp;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int cnt = 0;
    int b_i = 0;
    while (hp > 0) {
        if (b_i < n && b[b_i] > a[0]) {
            hp -= b[b_i++];
            cnt++;
        } else {
            int temp = hp / a[0];
            if (temp == 0) {
                cnt++;
                break;
            }
            hp -= temp * a[0];
            cnt += temp;
        }
    }
    cout << cnt << endl;
}
