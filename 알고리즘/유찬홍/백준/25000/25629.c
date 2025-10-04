#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        r += a & 1;
    }
    printf("%d", n / 2 + n % 2 == r);
}
