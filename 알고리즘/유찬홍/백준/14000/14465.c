#include <stdio.h>

int main() {
    int n, k, b, a[100001] = {};
    scanf("%d %d %d", &n, &k, &b);
    for (int i = 0, j; i < b; i++) {
        scanf("%d", &j);
        a[j] = 1;
    }
    int r = 1e9, w = 0;
    for (int i = 1; i <= k; i++) if (a[i]) w++;
    for (int i = k + 1; i <= n; i++) {
        if (a[i - k]) w--;
        if (a[i]) w++;
        if (r > w) r = w;
    }
    printf("%d", r);
}
