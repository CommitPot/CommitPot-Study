#include <stdio.h>

int v[100001];

int f(int x) {
    if (v[x] == x) return x;
    return v[x] = f(v[x]);
}

int u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return 0;
    v[x < y ? x : y] = x > y ? x : y;
    return 1;
}

int main() {
    int n, m, a, b, c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) v[i] = i;
    while (m--) {
        scanf("%d %d", &a, &b);
        if (!u(a, b)) c++;
    }
    for (int i = 1; i <= n; i++) {
        if (i == v[i]) c++;
    }
    printf("%d", c - 1);
}
