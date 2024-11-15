#include <stdio.h>

int main() {
    long long n, i = 1, r = 0;
    scanf("%lld", &n);
    while (n) {
        if (n & 1) r += i;
        n >>= 1, i *= 3;
    }
    printf("%lld", r);
}
