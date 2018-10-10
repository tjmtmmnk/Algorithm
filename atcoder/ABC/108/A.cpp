#include <stdio.h>

int main(void) {
    int k;
    scanf("%d", &k);
    int count = 0;

    for (int i = 1; i <= k; ++i) {
        if (i % 2 == 0) {
            for (int j = 1; j <= k; ++j) {
                if (j % 2 == 1) {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}