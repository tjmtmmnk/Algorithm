#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
typedef vector<int> vi;

/*
 * 考え方
 * 累積和のようにACという文字列が出現したインデックス情報とカウント情報を持っておく
 * そうすると、rightのカウント - leftのカウント が求めたい出現回数になる
*/

int main(void) {
    int str_length, question_num;
    vi accumulation_ac_count_by_postion_of_str(10e5 + 1, 0);
    string str;
    cin >> str_length >> question_num >> str;
    vi answer(question_num, 0);

    int accumulation_ac_count = 0;
    for (int i = 0; i < str_length; ++i) {
        accumulation_ac_count_by_postion_of_str[i] = accumulation_ac_count;
        if (i < str_length - 1 && str[i] == 'A' && str[i + 1] == 'C') accumulation_ac_count++;
    }

    for (int i = 0; i < question_num; ++i) {
        int left, right;
        cin >> left >> right;
        left--;
        right--;

        answer[i] = accumulation_ac_count_by_postion_of_str[right] - accumulation_ac_count_by_postion_of_str[left];
    }

    for (auto ans: answer) {
        cout << ans << endl;
    }
}