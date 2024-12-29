#include <stdio.h>

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0) return 0;
        printf("%d %d / %d\n", a / b, a % b, b);
    }
}