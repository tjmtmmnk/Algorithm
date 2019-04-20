#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int ant[5];
    int max;
    for (int i = 0; i < 5; ++i) {
        cin >> ant[i];
    }
    cin >> max;

    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            int dist = abs(ant[i] - ant[j]);
            if (dist > max) {
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
}