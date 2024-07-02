#include <stdio.h>

long long f(int x) {
    if (x == 1) return 1;
    return x * f(x - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n) / 604800);
}
