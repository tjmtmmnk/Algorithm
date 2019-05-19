#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
 int n,k;
 string s;
 cin >> n >> k >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(i==k-1){
            cout << (char)(s[i]+32);
        } else {
            cout << s[i];
        }
    }
    cout << endl;
}