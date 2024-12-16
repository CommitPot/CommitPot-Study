#include <stdio.h>

int main() {
    int n, a;
    long long i;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        for (i = 1; i <= a; i *= 10);
        printf("%lld\n", i / 2 < a ? i / 2 * (i / 2 - 1) : (i - a - 1) * a);
    }
}
