#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int a, b, c, d;
    scanf("%lld %lld", &a, &b);
    c = a + b, d = (abs(a - b) + 1);
    printf("%lld", c * d / 2);
    return 0;
}