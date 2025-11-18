#include <stdio.h>

int main() {
    long long n, b;
    scanf("%lld %lld", &n, &b);
    printf("%s", n <= (1LL << b + 1) - 1 ? "yes" : "no");
}
