#include <stdio.h>

int t[10001][2], p[10001], d[10001], cnt, r[10001][2];

void f(int v) {
    if (v == -1) return;
    f(t[v][0]);
    d[v] = cnt++;
    f(t[v][1]);
}

void f1(int v, int w) {
    if (v == -1) return;
    f1(t[v][0], w + 1);
    if (d[v] < r[w][0]) r[w][0] = d[v];
    if (d[v] > r[w][1]) r[w][1] = d[v];
    f1(t[v][1], w + 1);
}

int main() {
    int n, rs, rsw = -1;
    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        t[a][0] = b, t[a][1] = c;
        if (b != -1) p[b] = a;
        if (c != -1) p[c] = a;
    }
    for (int i = 1; i <= n; i++) {
        if (!p[i]) rs = i;
    }
    f(rs);
    for (int i = 1; i <= n; i++) r[i][0] = 1e9, r[i][1] = -1;
    f1(rs, 1);
    for (int i = 1; i <= n; i++) {
        if (r[i][0] == 1e9 || r[i][1] == -1) continue;
        if (rsw < r[i][1] - r[i][0] + 1) {
            rs = i;
            rsw = r[i][1] - r[i][0] + 1;
        }
    }
    printf("%d %d", rs, rsw);
}
