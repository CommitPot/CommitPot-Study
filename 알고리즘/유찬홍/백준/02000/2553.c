#include <stdio.h>

int main() {
    int n;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r *= i;
        while (!(r % 10)) r /= 10;
        r %= 1000000;
    }
    printf("%lld", r % 10);
}
