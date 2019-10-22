#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

/*
 * 考え方
 * 長方形の面積 < 正方形の面積
 * なので最長の辺が4本あるときは正方形を作る
 * 4本未満のときは次に長い辺とで長方形を作る
 * 2本以上あっても4本未満である辺が1個以下のときは長方形を作れない
 * */
int main(void) {
    int n;
    cin >> n;
    unordered_map<int, ll> length_and_count;
    for (int i = 0; i < n; ++i) {
        int length;
        cin >> length;
        length_and_count[length]++;
    }
    vll can_be_rectangle_length;
    for (const auto kv: length_and_count) {
        if (kv.second >= 2) {
            can_be_rectangle_length.push_back(kv.first);
        }
    }
    if (can_be_rectangle_length.size() == 0) {
        cout << 0 << endl;
    } else if (can_be_rectangle_length.size() == 1) {
        if (length_and_count[can_be_rectangle_length[0]] >= 4) {
            cout << can_be_rectangle_length[0] * can_be_rectangle_length[0] << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        sort(can_be_rectangle_length.begin(), can_be_rectangle_length.end(), greater<ll>());
        ll top_and_bottom = can_be_rectangle_length[0];
        ll left_and_right = length_and_count[top_and_bottom] >= 4 ? top_and_bottom : can_be_rectangle_length[1];
        cout << top_and_bottom * left_and_right << endl;
    }
}