#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    long long int N;
    long long int acom[5];
    vector<long long int> acom_max(5);
    cin >> N;
    for (int i = 0; i < 5; ++i) {
        cin >> acom[i];
        acom_max[i] = (N % acom[i] == 0) ? N / acom[i] : N / acom[i] + 1;
    }

    cout << *max_element(acom_max.begin(),acom_max.end()) + 4 << endl;

}