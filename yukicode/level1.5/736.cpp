//AC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) {
    int n;
    vector<ll> a;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    const vector<ll> b = a;

    sort(a.begin(), a.end());

    ll cd = gcd(a[0], a[1]);

    for (int j = 1; j < n; ++j) {
        cd = gcd(a[j], cd);
    }

    for (int k = 0; k < n; ++k) {
        if (cd == 1) {
            cout << b[k];
        } else {
            cout << b[k] / cd;
        }
        if (k != n - 1) {
            cout << ":";
        }
    }
    cout << endl;
}