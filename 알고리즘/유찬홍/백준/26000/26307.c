#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", (a - 9) * 60 + b);
    return 0;
}