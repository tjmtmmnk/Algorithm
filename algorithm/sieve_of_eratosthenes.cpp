#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(void) {
    int remove = 2;
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, false);
    vector<int> prime(n + 1);

    for (int i = 2; i <= n; ++i) {
        is_prime[i] = true;
    }

    int p = 0;

    // O(nlog(log n))  ≒ O(n)
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            // 素数の倍数をふるいにかける
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

//    for (auto pr : prime) {
//        cout << pr << "\t";
//    }
//    cout << endl;

    cout << p << endl;
}