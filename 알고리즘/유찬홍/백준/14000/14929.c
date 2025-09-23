#include <stdio.h>

int main() {
    int n, s = 0;
    long long r = 0;
    scanf("%d %d", &n, &s);
    for (int i = 1, j; i < n; i++) {
        scanf("%d", &j);
        r += j * s;
        s += j;
    }
    printf("%lld", r);
}
