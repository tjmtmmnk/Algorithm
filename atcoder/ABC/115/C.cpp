#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

//AC
int main(void) {
    vector<long long int> h;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        long long int temp;
        cin >> temp;
        h.push_back(temp);
    }

    sort(h.begin(), h.end());

    long long int m = 9999999999;
    for (int i = 0; i < (N - K + 1); ++i) {
        m = min(h[K + i - 1] - h[i], m);
    }
    cout << m << endl;
}