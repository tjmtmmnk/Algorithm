#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(b / a, c) << endl;
}