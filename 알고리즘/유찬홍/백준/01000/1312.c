#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    a %= b;
    while (n > 1) {
        a *= 10;
        a %= b;
        n--;
    }
    printf("%d", a * 10 / b);
    return 0;
}