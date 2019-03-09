#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int L[8];
int A, B, C;

int dfs(int k, int a, int b, int c) {
    if (k == N) {
        if (a == 0 || b == 0 || c == 0) return 1e9;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }
    int ans = 1e9;
    ans = min(ans, dfs(k + 1, a, b, c));
    ans = min(ans, dfs(k + 1, a + L[k], b, c) + (a > 0 ? 10 : 0));
    ans = min(ans, dfs(k + 1, a, b + L[k], c) + (b > 0 ? 10 : 0));
    ans = min(ans, dfs(k + 1, a, b, c + L[k]) + (c > 0 ? 10 : 0));

    return ans;
}

int main() {
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    cout << dfs(0, 0, 0, 0) << endl;
}