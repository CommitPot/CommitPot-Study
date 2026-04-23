#include <stdio.h>

int main() {
    long long n, r = 0;
    scanf("%lld", &n);
    while (n > 2) {
        if (n % 5) n -= 3, r++;
        else r += n / 5, n %= 5;
    }
    printf("%lld", n ? -1 : r);
}
