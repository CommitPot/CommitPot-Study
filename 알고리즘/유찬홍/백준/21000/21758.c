#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, a[100001], r = 0;
    scanf("%d %d", &n, &a[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > r && i < n - 1) r = a[i];
        a[i] += a[i - 1];
    }
    r = r + a[n - 2] - a[0];
    for (int i = 1; i < n - 1; i++) {
        r = max(r, a[n - 1] - a[0] - a[i] + a[i - 1] + a[n - 1] - a[i]);
        r = max(r, a[n - 2] - a[i] + a[i - 1] * 2);
    }
    printf("%d", r);
}
