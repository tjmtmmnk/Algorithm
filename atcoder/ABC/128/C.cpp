#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
typedef vector<int> vi;

/*
 * 考え方
 * N,M <= 10 なので、Nまで全ビット探索出来る
 * 全ビットを並べてx桁目の値をスイッチxのオンオフと対応させる
 * 例えば 10 なら スイッチ1がオフ, スイッチ2がオン
 * そうして電球AiにつながるスイッチSAiのオンになっている個数の2の余りがpiと一致するかを確認する
 * これを全電球に対して確認することで同じスイッチを共有していたとしても正しくカウントすることが出来る
 * また、n=1のときは例えば 1 1 1 1 0 といった入力の時に1が出力されてしまうので特殊な処理とした
 * */
int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vi> s(m, vi(11, 0));
    vi p(m, 0);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    int ans = 0;

    if (n == 1) {
        cout << p[0] << endl;
        return 0;
    }

    for (int bit = 0; bit < (1 << n); ++bit) {
        bool is_cnt_up = true;
        for (int j = 0; j < m; ++j) {
            int on_num = 0;
            for (auto sk: s[j]) {
                if ((bit >> (sk - 1)) & 1) on_num++;
            }
            if (on_num % 2 != p[j])is_cnt_up = false;
        }
        if (is_cnt_up) ans++;
    }

    cout << ans << endl;
}
