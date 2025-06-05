#include <stdio.h>

int main() {
    int n, m, k = 0, a[58] = {};
    char g[3001], s[3000001];
    scanf("%d %d %s %s", &n, &m, g, s);
    for (int i = 0; g[i]; i++) a[g[i] - 65]++;
    for (int i = 0; i < n; i++) {
        if (a[s[i] - 65] > 0) k++;
        a[s[i] - 65]--;
    }
    int r = k == n;
    for (int i = n; i <= m; i++) {
        if (a[s[i - n] - 65] + 1 > 0) k--;
        a[s[i - n] - 65]++;
        if (a[s[i] - 65] > 0) k++;
        a[s[i] - 65]--;
        if (k == n) r++;
    }
    printf("%d", r);
}
