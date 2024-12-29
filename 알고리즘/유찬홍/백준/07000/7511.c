#include <stdio.h>

int d[1000001];

int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}

int u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return 0;
    d[x > y ? y : x] = x > y ? x : y;
    return 1;
}

int main() {
    int t, n, k, a, b, m;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &k);
        for (int j = 0; j <= n; j++) {
            d[j] = j;
        }
        for (int j = 0; j < k; j++) {
            scanf("%d %d", &a, &b);
            u(a, b);
        }
        scanf("%d", &m);
        printf("Scenario %d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d %d", &a, &b);
            printf("%d\n", f(a) == f(b) ? 1 : 0);
        }
        printf("\n");
    }
}
