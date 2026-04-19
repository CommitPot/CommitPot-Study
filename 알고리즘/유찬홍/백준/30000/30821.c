#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120);
}
