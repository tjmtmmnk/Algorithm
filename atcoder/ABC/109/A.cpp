//AC
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a * b) % 2 == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}