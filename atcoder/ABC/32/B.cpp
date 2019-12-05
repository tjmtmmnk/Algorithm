#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>
#include <set>

using namespace std;

int main(void) {
    string s;
    int k;
    cin >> s >> k;

    set<string> pass;
    int cnt = 0;
    for (int i = 0; i < max<int>(s.length() - k + 1, 0); ++i) {
        string tgt_str = s.substr(i, k);
        auto itr = pass.find(tgt_str);
        bool is_exist = itr != pass.end();
        if (!is_exist) {
            cnt++;
            pass.insert(tgt_str);
        }
    }
    cout << cnt << endl;
}