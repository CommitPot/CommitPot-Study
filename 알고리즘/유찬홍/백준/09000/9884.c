#include <stdio.h>

int f(int a, int b) {
    if (a == b) return b;
    return f(a > b ? a - b : b - a, a > b ? b : a);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a > b ? f(a, b) : f(b, a));
}
