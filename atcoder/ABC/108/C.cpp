#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    int count = 0;

    if (k % 2 == 1) {
        for (int i = 1; i <= n; i = 2 * i - 1) {
            if (i % k == 0) {
                for (int j = 1; j <= n; j = 2 * j - 1) {
                    if (j % k == 0) {
                        for (int l = 1; l <= n; l = 2 * l - 1) {
                            if (l % k == 0) {
                                count++;
                            }
                        }
                    }
                }
            }
        }

    } else {
        for (int i = 1; i <= n; i++) {
            if (i % k == 0) {
                for (int j = 1; j <= n; j++) {
                    if (j % k == 0) {
                        for (int l = 1; l <= n; l++) {
                            if (l % k == 0) {
                                count++;
                            }
                        }
                    }
                }
            }

            if (i % k == 1) {
                for (int j = 1; j <= n; ++j) {
                    if (j % k == 1) {
                        for (int l = 1; l <= n; ++l) {
                            if (l % k == 1) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count);
}