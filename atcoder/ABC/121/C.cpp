#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long int, int> P;

bool pairCompare(const P &firstElof, const P &secondElof) {
    return firstElof.first < secondElof.first;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<P> shop(n);

    for (int i = 0; i < n; ++i) {
        cin >> shop[i].first >> shop[i].second;
    }

    sort(shop.begin(), shop.end(), pairCompare);

    long long int money = 0;
    int num = m;

    int end;
    for (int i = 0; i < n; ++i) {
        if ((num - shop[i].second) <= 0) {
            end = i;
            break;
        } else {
            num -= shop[i].second;
            money += shop[i].first * shop[i].second;
        }
    }

    for (int j = 0; j < shop[end].second; ++j) {
        if (num == 0) {
            break;
        } else {
            money += shop[end].first;
            num--;
        }
    }

    cout << money << endl;
}