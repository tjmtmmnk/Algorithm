#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

/*
 * 考え方
 * ヒント文字列のtの値か '?' であれば文字列としては一致する
 * それがtの文字数分続けば、置換することが出来る
 * それを繰り返して置換したものをvectorに追加していく
 * 辞書順最小のものが鍵になるので '?' は全て 'a'　と置き換えることが出来る
 * '?' を 'a' に置き換えて昇順ソートしてはじめの値が鍵となる、そもそもvectorのサイズが0なら鍵は存在しない
*/
int main(void) {
    string s, t;
    cin >> s >> t;
    vector<string> keys;
    vector<string> replaced_keys;
    int s_length = s.length();
    int t_length = t.length();
    for (int i = 0; i < s_length; ++i) {
        string s_copy = s;
        bool is_match = true;
        for (int j = 0; j < t_length; ++j) {
            if (i + j < s_length) {
                if ((s_copy[i + j] != t[j]) && (s_copy[i + j] != '?')) {
                    is_match = false;
                }

                if (is_match && j == t_length - 1) {
                    s_copy.replace(i, t_length, t);
                    keys.push_back(s_copy);
                    break;
                }
            }
        }
    }

    for (auto k : keys) {
        replace(k.begin(), k.end(), '?', 'a');
        replaced_keys.push_back(k);
    }

    sort(replaced_keys.begin(), replaced_keys.end());

    if (replaced_keys.size()) {
        cout << replaced_keys[0] << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
}