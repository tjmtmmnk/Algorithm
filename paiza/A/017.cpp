//AC
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int H, W, N;
    int h[50], w[50], x[50];

    cin >> H >> W >> N;
    for (int i = 0; i < N; ++i) {
        cin >> h[i] >> w[i] >> x[i];
    }

    char plain[30][30];

    for (int h_i = 0; h_i < H; ++h_i) {
        for (int w_i = 0; w_i < W; ++w_i) {
            plain[h_i][w_i] = '.';
        }
    }

    bool is_bottom = false;

    for (int i = 0; i < N; ++i) {
        for (int line = 0; line < H; ++line) {
            for (int col = x[i]; col < (x[i] + w[i]); ++col) {
                if (plain[line][col] == '#') {
                    is_bottom = true;
                    break;
                }
            }
            if (is_bottom) {
                for (int h_i = line - 1; h_i > line - 1 - h[i]; --h_i) {
                    for (int w_i = x[i]; w_i < (x[i] + w[i]); ++w_i) {
                        plain[h_i][w_i] = '#';
                    }
                }
                break;
            }
            if (line == H - 1) {
                for (int h_i = line; h_i > line - h[i]; --h_i) {
                    for (int w_i = x[i]; w_i < (x[i] + w[i]); ++w_i) {
                        plain[h_i][w_i] = '#';
                    }
                }
                break;
            }
        }
        is_bottom = false;
    }

    for (int h_i = 0; h_i < H; ++h_i) {
        for (int w_i = 0; w_i < W; ++w_i) {
            cout << plain[h_i][w_i];
        }
        cout << endl;
    }
}