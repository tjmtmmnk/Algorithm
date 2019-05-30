#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;

int main(void) {
    int a, b;
    cin >> a >> b;
    if (a <= 5) {
        cout << 0 << endl;
    } else if (6 <= a && a <= 12) {
        cout << b / 2 << endl;
    } else {
        cout << b << endl;
    }
}