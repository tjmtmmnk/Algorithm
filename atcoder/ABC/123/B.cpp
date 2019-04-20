#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    vector<int> time(5);
    vector<int> han(5);
    for (int i = 0; i < 5; ++i) {
        cin >> time[i];
        if (time[i] % 10 != 0) { han.push_back(10 - time[i] % 10); }
    }
    int sum = 0;
    std::vector<int>::iterator maxIt = std::max_element(han.begin(), han.end());

    int x = 0;
    for (int i = 0; i < 5; ++i) {
        if ((10 - time[i] % 10) == han[distance(han.begin(), maxIt)]) {
            x = i;
            break;
        }
    }

    for (int i = 0; i < 5; ++i) {
        if(x != i){
            sum += time[i];
            sum += (time[i] % 10 == 0) ? 0 : 10 - (time[i] % 10);
        }
    }

    sum += time[x];

    cout << sum << endl;
}