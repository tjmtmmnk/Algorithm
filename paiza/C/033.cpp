//AC
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    pair<string, int> ball = make_pair("ball", 0);
    pair<string, int> strike = make_pair("strike", 0);
    string input[10];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < n; ++i) {
        if (ball.first == input[i]) {
            ball.second++;
            if (ball.second < 4) { cout << "ball!" << endl; }
            else if (ball.second == 4) { cout << "fourball!" << endl; }
        }
        if (strike.first == input[i]) {
            strike.second++;
            if (strike.second < 3) { cout << "strike!" << endl; }
            else if (strike.second == 3) { cout << "out!" << endl; }
        }
    }
}