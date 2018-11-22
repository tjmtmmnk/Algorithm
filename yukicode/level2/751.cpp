//AC
#include <iostream>
#include <string>

typedef long long int ll;

using namespace std;

int gcf(int a, int b) {
    if (b == 0) { return a; }
    return gcf(b, a % b);
}

int main(void) {
    int A[20], B[20];
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> A[i];
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> B[i];
    }

    ll A_deno = A[0];
    ll A_nume = 1;
    for (int i = 1; i < n1; ++i) {
        A_nume *= A[i];
    }

    ll B_deno = 1;
    ll B_nume = 1;
    for (int i = 0; i < n2; ++i) {
        if (i % 2 == 0) {
            B_nume *= B[i];
        } else {
            B_deno *= B[i];
        }
    }

    ll g_a = gcf(abs(A_deno), abs(A_nume));
    ll g_b = gcf(abs(B_deno), abs(B_nume));

    A_deno /= g_a;
    A_nume /= g_a;
    B_deno /= g_b;
    B_nume /= g_b;

    ll deno = A_deno * B_deno;
    ll nume = A_nume * B_nume;
    ll g = gcf(abs(deno), abs(nume));

    deno = (nume < 0) ? -deno : deno;
    nume = (nume < 0) ? -nume : nume;

    cout << deno / g << " " << nume / g << endl;
}