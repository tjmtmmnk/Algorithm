// AC
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
    double r,d;
    cin >> r >> d;
    cout << std::setprecision(11) << sqrt(d * d - r * r) << endl;
}