#include <stdio.h>

int main() {
    int n, a[500001];
    long long r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), s += a[i];
    for (int i = 0; i < n - 1; i++) {
        s -= a[i];
        r += a[i] * s;
    }
    printf("%lld", r);
}
