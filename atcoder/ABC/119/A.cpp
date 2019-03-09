#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int month = stoi(s.substr(5, 6));

    if (month <= 4) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }
}