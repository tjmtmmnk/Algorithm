#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int h[101];
int N;

bool isComplete() {
    for (int i = 0; i < N; ++i) {
        if (h[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int step = 0;
    int head = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    while (!isComplete()) {
        for (int i = 0; i < N; ++i) {
            if (h[i] != 0) {
                head = i;
                break;
            }
        }

        for (int j = head; h[j] != 0 && j < N; ++j) {
            h[j] -= 1;
        }
        step++;
    }
    cout << step << endl;
}
