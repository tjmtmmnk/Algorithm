// p35 : Lake Counting(POJ No.2386)

#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_M 100

int horiz, vertical;
char garden[MAX_N + 2][MAX_M + 2];

int countLake() {
    int count = 0;
    bool is_break = false;

    for (int i = 1; i < horiz; ++i) {
        for (int j = 1; j < vertical; ++j) {
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    if (garden[i][j] == 'W' && garden[i + k][j + l] == 'W') {
                        is_break = true;
                    } else{
                        is_break = false;
                    }
                }
            }
            if (is_break) {
                count++;
            }
            is_break = false;
        }
    }

    return count;
}

int main(void) {

    cin >> vertical >> horiz;

    for (int i = 0; i < MAX_N + 2; ++i) {
        for (int j = 0; j < MAX_M + 2; ++j) {
            garden[i][j] = '.';
        }
    }

    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < horiz; ++j) {
            cin >> garden[i + 1][j + 1];
        }
    }

    cout << countLake() << endl;
}