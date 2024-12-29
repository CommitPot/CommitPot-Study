#include <stdio.h>

int main() {
    int n, r;
    scanf("%d", &n);
    r = n;
    do for (int j = 2; j * j <= n; j++) if (n % j == 0) r++; while (n-- > 1);
    printf("%d", r);
}
