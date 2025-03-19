#include <stdio.h>

int f(int a) {
    if (!a) return 1;
    return !!(a % 10) & f(a / 10);
}

int main() {
    int n;
    scanf("%d", &n);
    while (!f(++n));
    printf("%d", n);
}
