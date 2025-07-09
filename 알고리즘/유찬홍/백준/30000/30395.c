#include <stdio.h>

int main() {
    int n, a[1002], r = 0, b = 0;
    scanf("%d", &n);
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (!a[i] && a[i - 1] && a[i + 1]) a[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) b += a[i] > 0;
        else b = 0;
        r = r < b ? b : r;
    }
    printf("%d", r);
}
