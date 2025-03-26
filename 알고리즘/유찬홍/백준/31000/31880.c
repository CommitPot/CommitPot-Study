#include <stdio.h>

int main() {
    int n, m, a;
    long long r = 0;
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf("%d", &a);
        r += a;
    }
    while (m--) {
        scanf("%d", &a);
        if (a) r *= a;
    }
    printf("%lld", r);
}
