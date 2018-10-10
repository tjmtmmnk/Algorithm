#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

template<typename T>
int binary_search_find_index(std::vector<T> v, int data) {
    auto it = std::lower_bound(v.begin(), v.end(), data);
    if (it == v.end() || *it != data) {
        return -1;
    } else {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }
}

int solve(){

}

int main(void) {
    ll x, n;
    int idx;
    int count = 0;
    vector<ll> a;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    for (int j = 0; j < n; ++j) {
        if ((idx = binary_search_find_index<ll>(a, x - a[j])) >= 0) {
            for (int i = idx; i < n; ++i) {
                if (a[i] == x - a[j]) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}