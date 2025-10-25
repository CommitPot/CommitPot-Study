#include <stdio.h>

int main() {
    int n;
    long long a[500002], s = 0, w, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), s += a[i];
    a[n] = 0, w = s / n;
    for (int i = 0; i < n * 2 - 1; i++) {
        if (a[i % n] > w) {
            long long g = a[i % n] - w;
            r += g, a[i % n] = w, a[(i + 1) % n] += g;
        }
    }
    printf("%lld", r);
}
