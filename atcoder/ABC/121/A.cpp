#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H - h) * (W - w) << endl;
}