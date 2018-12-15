//AC
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
#define repe(i, s, n) for(int i = s;i<=n;i++)
using ll = long long int;

int main(void) {
    int K, S;
    int cnt = 0;
    cin >> K >> S;
    repe(x, 0, K) {
        repe(y, 0, K) {
            int z = S - x - y;
            if (z >= 0 && z <= K) { cnt++; }
        }
    }
    cout << cnt << endl;
}
