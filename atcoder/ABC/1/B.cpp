#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef vector<int> vi;

/*
 * 考え方
 * 操作としては 何もしない/+-1℃/+-5℃/10℃のいずれか
 * それぞれ計算してみて最も目標とする温度に近づいた操作を採用するということを繰り返せばいい
*/
int main(void) {
    int target_temp, now_temp;
    cin >> target_temp >> now_temp;

    int cnt = 0;
    while (1) {
        if (now_temp == target_temp) {
            break;
        } else {
            cnt++;
            vi operated_temp{now_temp + 10, now_temp - 10,
                             now_temp + 5, now_temp - 5,
                             now_temp + 1, now_temp - 1,
                             now_temp};

            int min_diff = 1010222;
            int closest_temp;
            for (auto t : operated_temp) {
                int _temp = abs(target_temp - t);
                if (_temp < min_diff) {
                    min_diff = _temp;
                    closest_temp = t;
                }
            }

            now_temp = closest_temp;
        }
    }
    cout << cnt << endl;
}