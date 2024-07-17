#include <stdio.h>

int l[10001] = {10000};

int f(int v, int p, int n) {
    if (v == n) return l[p];
    if (l[v] > 10000) return l[0];
    int x = l[v];
    l[v] = l[p] + 1;
    return f(x, v, n);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
        printf("%d\n", f(1, 0, n) - 10000);
    }
}
