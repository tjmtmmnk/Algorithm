#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<ll> vll;

/*
 * 考え方
 * アナグラムを比較するために文字列をsortしてしまう
 * さらに文字列の配列全体でもソートすることで、数え上げやすくする
 * 結局、アナグラムの組み合わせというのはアナグラムが同じになる集合の数xから2個取り出すことと同じで xC2 で求まる
 * これを各集合に対して計算して足し合わせればいい
*/
int main(void) {
    int n;
    cin >> n;
    vector<string> s(n);
    vll anagram_count;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());

    ll cnt = 1;
    string prev_str = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] != prev_str) {
            if (cnt > 1) {
                anagram_count.pb(cnt);
                cnt = 1;
            }
        } else {
            cnt++;
            if (i == n - 1 && cnt > 1) anagram_count.pb(cnt);
        }
        prev_str = s[i];
    }

    ll ans = 0;
    for (auto ana_count : anagram_count) {
        ans += (ll) (ana_count == 1 ? 1 : ana_count * (ana_count - 1) / 2);
    }
    cout << ans << endl;
}