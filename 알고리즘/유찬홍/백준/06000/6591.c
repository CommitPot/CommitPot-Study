#include <stdio.h>

long long f(int a, int b) {
    if (a == b || !b) return 1;
    return a * f(a - 1, b - 1) / b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a) {
        printf("%lld\n", f(a, a - b > b ? b : a - b));
        scanf("%d %d", &a, &b);
    }
}
