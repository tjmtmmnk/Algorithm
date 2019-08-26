#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
 * 考え方
 * 辞書順最小という制約があるので、'('がなるべく先頭に、')'がなるべく末尾に来たら良い
 * '('の数と')'の数は一致しないといけないので、right_countを増やす時にleft_countが正数ならデクリメントして調整する
 * left_countから見ることが重要で、'(((...' のようなものは先頭に '(' を追加できないので、')))...' のようなものを考慮する
*/
int main(void) {
    int n;
    string s;
    cin >> n >> s;

    int right_count = 0, left_count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left_count++;
        } else {
            if (left_count > 0) left_count--;
            else right_count++;
        }
    }

    string ans = "";

    for (int i = 0; i < right_count; i++) {
        ans += "(";
    }
    ans += s;
    for (int i = 0; i < left_count; i++) {
        ans += ")";
    }
    cout << ans << endl;
}