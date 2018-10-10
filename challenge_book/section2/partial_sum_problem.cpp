// p34 部分和問題

#include <iostream>

using namespace std;

int num, tgt_sum;
int a[20];

bool dfs(int i, int sum) {
    if (i == num) {
        return sum == tgt_sum;
    }
    if (dfs(i + 1, sum)) {
        return true;
    }
    if (dfs(i + 1, sum + a[i])) {
        return true;
    }
    return false;
}

int main(void) {
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> a[i];
    }
    cin >> tgt_sum;

    if (dfs(0, 0)) {
        cout << "find" << endl;
    } else {
        cout << "not found" << endl;
    }
}

