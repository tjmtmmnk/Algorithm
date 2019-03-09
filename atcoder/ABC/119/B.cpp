#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int n;
    double sum;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        float money;
        string type;
        cin >> money >> type;
        if (type == "JPY") {
            sum += money;
        } else {
            sum += (money * 380000.0f);
        }
    }

    cout << sum << endl;
}