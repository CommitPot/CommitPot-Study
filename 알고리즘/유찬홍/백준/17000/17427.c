#include <stdio.h>

int main() {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) r += n / i * i;
    printf("%lld", r);
}
