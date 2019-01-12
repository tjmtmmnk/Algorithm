// AC time : 198ms, memory : 4224KB

/*上位コードはビット演算を使った部分和問題解法
int n;
bitset<10001> dp(1);

int main(){
  cin >> n;

  REP(i,n){
    int  p;
    cin >> p;
    dp |= dp << p;
  }

  cout << dp.count() << endl;
  return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int p[101];
int dp[101][10001];

int dfs(int i, int sum) {
    if (dp[i][sum] >= 0) { return dp[i][sum]; }
    if (i == N) { return sum; }
    dp[i][sum] = dfs(i + 1, sum);
    dp[i][sum] = dfs(i + 1, sum + p[i]);
    return sum;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 10001; ++j) {
            dp[i][j] = -1;
        }
    }

    dfs(0, 0);

    vector<int> list;

    int cnt = 0;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 10001; ++j) {
            if (dp[i][j] >= 0) {
                auto ie = find(list.begin(), list.end(), dp[i][j]);
                if (ie == list.end()) { list.push_back(dp[i][j]); }
            }
        }
    }
    cout << list.size() + 1 << endl;
}
