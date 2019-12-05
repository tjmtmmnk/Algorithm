#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <math.h>
#include <cmath>

using namespace std;

int main(void) {
    int short_hand, long_hand;
    cin >> short_hand >> long_hand;
    short_hand = short_hand >= 12 ? short_hand - 12 : short_hand;
    float short_degree = (float) short_hand * 30 + (float) long_hand * 0.5f;
    float long_degree = (float) long_hand * 6.0f;
    float ans = min(360.0f - abs(short_degree - long_degree), abs(short_degree - long_degree));
    cout << ans << endl;
}