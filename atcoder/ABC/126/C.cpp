#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    std::cout << std::fixed << std::setprecision(10);

    for (int i = 1; i <= n; ++i) {
        int times = 0;
        int x = i;
        for (int j = 0; j < k; ++j) {
            if (x >= k) {
                break;
            } else if (1 <= x && x <= (k - 1)) {
                x *= 2;
                times++;
            }
        }
        double kake = 1;
        for (int l = 0; l < times; ++l) {
            kake /= 2.0f;
        }
        if (times == 0) {
            ans += kake/n;
        } else {
            ans += (kake / (double) (n));
        }
    }
    cout << ans << endl;
}