#include <stdio.h>

int main() {
    int n, k, a[100001], r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < k; i++) r += a[i];
    for (int i = k, x = r; i < n + k - 1; i++) {
        x = x - a[(i - k + n) % n] + a[i % n];
        r = r < x ? x : r;
    }
    printf("%d", r);
}
