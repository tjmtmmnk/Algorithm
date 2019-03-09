#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int n, m, c;
    int A[100][100], B[100];

    cin >> n >> m >> c;

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += A[i][j] * B[j];
        }
        if (sum+c > 0) { cnt++; }
    }

    cout << cnt << endl;
}