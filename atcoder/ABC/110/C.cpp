#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <map>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    string s, t;
    map<char, char> mp;
    vector<pair<char, int>> mt;
    int cnt = 0;
    cin >> s >> t;

    mp.insert(make_pair(s[0], t[0]));

    bool is_match = true;

    rep(i, 1, s.length()) {
        auto itr = mp.find(s[i]);

        if (s[i] == t[i]) {
            pair<char, int> temp;
            temp.first = s[i];
            temp.second = i;
            mt.push_back(temp);
        }

        if (itr == end(mp)) { // 見つからない場合
            mp.insert(make_pair(s[i], t[i]));
        } else {
            if (mp[s[i]] != t[i]) {
                is_match = false;
                break;
            }
        }
    }

    rep(i, 0, s.length()) {
        rep(j, 0, mt.size()) {
            if ((s[i] == mt[j].first && i != mt[j].second) || (t[i] == mt[j].first && i != mt[j].second)) {
                is_match = false;
                break;
            }
        }
    }

    if (is_match) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}