#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long ll;

int main(void) {
    ll s_num, c_num;
    cin >> s_num >> c_num;
    if ((2 * s_num - c_num) >= 0) {
        cout << min(s_num, c_num / 2) << endl;
    } else {
        cout << s_num + (c_num - 2 * s_num) / 4 << endl;
    }
}