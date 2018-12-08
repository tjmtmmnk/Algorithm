#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    vector<int> p_list;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        p_list.push_back(temp);
    }
    sort(p_list.begin(), p_list.end());

    int sum = 0;
    for (auto s : p_list) {
        sum += s;
    }
    sum -= p_list.back();
    sum += (p_list.back() / 2);
    cout << sum << endl;
}