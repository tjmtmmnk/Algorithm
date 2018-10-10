//AC

#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    int n;
    string sp;
    string speech_list[100];
    bool is_follow_rule = true;
    cin >> n >> sp;
    speech_list[0] = sp;

    for (int i = 1; i < n; ++i) {
        cin >> sp;
        speech_list[i] = sp;

        if (speech_list[i - 1][speech_list[i - 1].length() - 1] == speech_list[i][0] && is_follow_rule) {
            for (int j = 0; j < i; ++j) {
                if (speech_list[j].compare(speech_list[i]) != 0) {
                    is_follow_rule = true;
                } else {
                    is_follow_rule = false;
                    break;
                }
            }
        } else {
            is_follow_rule = false;
        }
    }

    if (is_follow_rule) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}