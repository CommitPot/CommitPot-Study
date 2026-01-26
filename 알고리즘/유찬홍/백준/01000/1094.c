#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 64; n; i >>= 1) r += n / i, n %= i;
    printf("%d", r);
}
