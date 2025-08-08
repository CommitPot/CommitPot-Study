#include <stdio.h>

int main() {
    int n, l, r = 0, a[1000001];
    scanf("%d %d %d", &n, &l, &a[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int x = i < l ? a[i] : a[i] - a[i - l];
        r += 128 < x && x < 139;
    }
    printf("%d", r);
}
