//WA
//TODO: 尺取法の実装
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

int n, k;
vector<priority_queue<long long int>> sushi(100001);
vector<long long int> zero_flag_set;
vector<long long int> one_flag_set;

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;
        sushi[t].push(d);
    }

    for (int i = 0; i <= n; ++i) {
        if (!sushi[i].empty()) {
            one_flag_set.push_back(sushi[i].top());
            sushi[i].pop();
            while (!sushi[i].empty()) {
                zero_flag_set.push_back(sushi[i].top());
                sushi[i].pop();
            }
        }
    }

    sort(one_flag_set.begin(), one_flag_set.end(), greater<long long int>());
    sort(zero_flag_set.begin(), zero_flag_set.end(), greater<long long int>());

    long long int ans = 0;
    long long int prev = 0;
    int of = one_flag_set.size();

    while (of > 0) {
        long long int o_temp = 0;
        for (int i = 0; (i < of) && (i < one_flag_set.size()); ++i) {
            o_temp += one_flag_set[i];
        }
        long long int z_temp = 0;
        for (int j = 0; j < (k - of) && (j < zero_flag_set.size()); ++j) {
            z_temp += zero_flag_set[j];
        }
        ans = max((o_temp + z_temp + (of * of)), prev);
        prev = ans;
        of--;
    }

    cout << ans << endl;
}