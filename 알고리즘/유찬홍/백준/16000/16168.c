#include <stdio.h>

int f(int x, int *v) {
    return v[x] = v[x] == x ? x : f(v[x], v);
}

void u(int x, int y, int *v) {
    x = f(x, v), y = f(y, v);
    v[x] = v[y];
}

int main() {
    int n, m, p[3001] = {}, v[3001], k = 0, r = -1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) v[i] = i;
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        p[a]++, p[b]++;
        u(a, b, v);
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] & 1) k++;
        if (f(i, v) != f(i - 1, v)) r++;
    }
    printf("%s", k > 2 || r ? "NO" : "YES");
}
