#include <iostream>
#include <vector>

using namespace std;

#define rep(i, s, n) for(int i = s;i<n;i++)

typedef pair<int, int> P;

bool pairCompare(const P &firstElof, const P &secondElof) {
    return firstElof.second > secondElof.second;
}

int main(void) {
    int n = 0, count = 0;
    vector<P> vp;
    vector<int> v, v_odd, v_even;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n / 2; i++) {
        v_odd.push_back(v[2 * i]);
    }

    for (int i = 0; i < n / 2; i++) {
        v_even.push_back(v[2 * i + 1]);
    }

    sort(v_odd.begin(), v_odd.end());
    sort(v_even.begin(), v_even.end());

    P temp;
    temp.second = 1;

    for (int i = 0; i < v_odd.size() - 1; ++i) {
        temp.first = v_odd[i];
        if (v_odd[i] == v_odd[i + 1]) {
            temp.second++;
            if (i + 2 == v_odd.size()) {
                vp.push_back(temp);
            }
        } else {
            vp.push_back(temp);
        }
    }
    sort(vp.begin(), vp.end(), pairCompare);

    P temp;
    temp.second = 1;

    for (int i = 0; i < v_even.size() - 1; ++i) {
        temp.first = v_even[i];
        if (v_even[i] == v_even[i + 1]) {
            temp.second++;
            if (i + 2 == v_even.size()) {
                vp.push_back(temp);
            }
        } else {
            vp.push_back(temp);
        }
    }
    sort(vp.begin(), vp.end(), pairCompare);
    cout << "val : " << vp.front().first << "\tcnt : " << vp.front().second << endl;
}