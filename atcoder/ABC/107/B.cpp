#include <iostream>

using namespace std;

int main(void) {
    int line, row;
    int cnt = 0;
    int ign_line[100] = {0};
    int ign_row[100] = {0};
    char a[100][100] = {'\0'};
    cin >> line >> row;

    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < row; ++j) {
            cin >> a[i][j];
        }
    }

    int ign_line_i = 0;
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < row; ++j) {
            if (a[i][j] == '.') { cnt++; }
            if (cnt == line) { ign_line[ign_line_i++] = i; }
        }
        cnt = 0;
    }

    cnt = 0;
    int ign_row_i = 0;

    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < row; ++j) {
            if (a[j][i] == '.') { cnt++; }
            if (cnt == row) { ign_row[ign_row_i++] = i; }
        }
        cnt = 0;
    }

    for (int i = 0; i < line; ++i) {
        for (int li = 0; li < ign_line_i; ++li) {
            if (i != ign_line[li]) {
                for (int j = 0; j < row; ++j) {
                    for (int ri = 0; ri < ign_row_i; ++ri) {
                        if (j != ign_row[ri]) {
                            cout << a[i][j];
                        }
                    }
                }
                cout << endl;
            }
        }
    }

}