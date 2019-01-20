#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

template<typename T>
bool vector_finder(std::vector<T> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
    if (index != vec.size()) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    vector<long long int> list;
    int n;

    cin >> n;

    list.push_back(n);

    while (1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        if (vector_finder<long long int>(list, n)) {
            cout << list.size() + 1 << endl;
            return 0;
        } else {
            list.push_back(n);
        }
    }
}
