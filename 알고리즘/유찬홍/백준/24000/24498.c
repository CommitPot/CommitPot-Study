#include <stdio.h>

int main() {
    int n, a[1000001], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n - 1; i++) {
        int x = a[i] + (a[i - 1] < a[i + 1] ? a[i - 1] : a[i + 1]);
        r = r < x ? x : r;
    }
    r = r < a[0] ? a[0] : r;
    r = r < a[n - 1] ? a[n - 1] : r;
    printf("%d", r);
}
