#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int ue = (s[0] - '0') * 10 + (s[1] - '0');
    int sita = (s[2] - '0') * 10 + (s[3] - '0');

    bool is_sy=false, is_uy=false, is_sm=false, is_um=false;

    if (0 <= ue && ue <= 99) is_uy = true;
    if (1 <= ue && ue <= 12) is_um = true;
    if (0 <= sita && sita <= 99) is_sy = true;
    if (1 <= sita && sita <= 12) is_sm = true;

    if (is_sy && is_sm && is_uy && is_um) cout << "AMBIGUOUS" << endl;
    else if (is_uy && is_sm) cout << "YYMM" << endl;
    else if (is_um && is_sy) cout << "MMYY" << endl;
    else cout << "NA" << endl;
}