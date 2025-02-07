#include <stdio.h>

int main() {
    long long k, n, v;
    scanf("%lld %lld", &k, &n);
    v = n * k / (n - 1);
    printf("%lld", n == 1 ? -1 : v + !!((n * k) % (n - 1)));
}
