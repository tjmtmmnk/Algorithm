#include <stdio.h>
#include <string>
#include <regex>

typedef long long int ll;

int countZero(int num, int *head) {
    int count = -1;
    int last = 0;
    for (; num >= 1 || num <= -1; ++count) {
        last = num;
        num /= 10;
    }
    *head = last;
    return count;
}

int main(void) {
    int a, b;
    long long int ans;
    scanf("%d%d", &a, &b);
    std::string str_a, str_b;
    str_a = std::to_string(a);
    str_b = std::to_string(b);

    ans = (ll) a * (ll) b;

    if (std::regex_search(str_a, std::regex("^-?[1-9]0{2,}$")) &&
        std::regex_search(str_b, std::regex("^-?[1-9]0{2,}$"))) {
        int a_head, a_zero;
        int b_head, b_zero;
        a_zero = countZero(a, &a_head);
        b_zero = countZero(b, &b_head);

        printf("%d", a_head * b_head);
        for (int i = 0; i < (a_zero + b_zero - 1); ++i) {
            printf("0");
        }
        printf("\n");
    } else {
        if (ans < -99999999 || ans > 99999999) {
            printf("E\n");
        } else {
            printf("%lld\n", ans);
        }
    }
}