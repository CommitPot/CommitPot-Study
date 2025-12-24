#include <stdio.h>
#include <string.h>

int main() {
    int n, m, r = 0;
    char a[1000001];
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) scanf(" %c", &a[i]);
    for (int i = 0, b, c; i < m; i++) {
        scanf(" %c %d", &b, &c);
        if (a[c] && a[c] <= b) r++, a[c] = 0;
    }
    printf("%d", r);
}
