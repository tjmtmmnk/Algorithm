//AC time : 1ms, memory : 256KB
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    long long int A, B, C, sum = 0;
    cin >> A >> B >> C;
    if ((A + B) >= C) { sum += (B + C); }
    else { sum += (A + 2 * B + 1); }
    cout << sum << endl;
}