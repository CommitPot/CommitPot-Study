#include <stdio.h>

int main() {
    long long int a, b, max, min;
    scanf("%lld %lld", &a, &b);
    max = a >= b ? a : b;
    min = a > b ? b : a;
    printf("%lld\n", max - min < 2 ? 0 : max - min - 1);
    for (long long int i = min + 1; i < max; i++) {
        printf("%lld ", i);
    }
    return 0;
}