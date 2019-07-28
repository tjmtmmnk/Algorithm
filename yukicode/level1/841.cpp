#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, s, n) for (int i = s; i < n; i++)
#define repe(i, s, n) for (int i = s; i <= n; i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
static const ll maxLL = (ll)1 << 62;
const ll MOD = 1000000007, INF = 1e18;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool isSatOrSun(string s)
{
    return s == "Sat" || s == "Sun";
}

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    if(isSatOrSun(s1) && isSatOrSun(s2)) {
        cout << "8/33" << endl;
    } else if(isSatOrSun(s1)){
        cout << "8/32" << endl;
    } else {
        cout << "8/31" << endl;
    }
}