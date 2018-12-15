//AC
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)
#define repe(i, s, n) for(int i = s;i<=n;i++)
using ll = long long int;

int main(void) {
    int N, Y;
    cin >> N >> Y;
    bool is_find = false;
    repe(x, 0, N && !is_find) {
        repe(y, 0, N) {
            int z = N - x - y;
            ll sum = 10000 * x + 5000 * y + 1000 * z;
            if (sum == Y && z>=0) {
                cout << x << " " << y << " " << z << endl;
                is_find = true;
                break;
            }
        }
    }
    if (!is_find) {
        cout << "-1 -1 -1" << endl;
    }
}
