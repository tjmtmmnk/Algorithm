#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;

int main(void) {
    int r, d, x;
    cin >> r >> d >> x;

    ll prev = r * x - d;
    for (int i = 1; i <= 10; ++i) {
        cout << prev << endl;
        prev = r * prev - d;
    }
}