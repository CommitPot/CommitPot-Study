#include <stdio.h>

int main() {
    int h, x, b;
    long long int sum = 0;
    scanf("%d %d", &h, &x);
    long long int a = x;
    for (int i = 0; i < h; i++) {
        scanf("%d", &b);
        sum += a * b;
        sum %= 1000000007;
        a *= x;
        a %= 1000000007;
    }
    printf("%lld", sum);
}
