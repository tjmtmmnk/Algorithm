//AC
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

int main(void) {
    string S, T;
    ll N, M, g, l;
    cin >> N >> M >> S >> T;
    g = gcd(N, M);
    l = N * M / g;

    for (int i = 0; i < g; ++i) {
        if (S[i * N / g] != T[i * M / g]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << l << endl;
}