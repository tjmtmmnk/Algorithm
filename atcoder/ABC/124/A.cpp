#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    int sum = (a >= b) ? a : b;
    if (sum == a) {
        a--;
        sum += (a >= b) ? a : b;
    }
    else if (sum == b) {
        b--;
        sum += (a >= b) ? a : b;
    }
    cout << sum << endl;
}