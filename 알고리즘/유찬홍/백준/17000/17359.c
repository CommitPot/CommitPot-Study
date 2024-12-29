#include <stdio.h>
#include <stdbool.h>

int n, a[10], d[10], vis[10], b[10], r = 1e9;

bool p(int x, int y) {
    if (!x) return y > 1;
    if (x == 1) return y < 2;
    if (x == 10) return y > 9;
    return y < 2;
}

void f(int l) {
    if (l == n) {
        int v = 0;
        for (int i = 1; i < l; i++) v += p(a[b[i - 1]], a[b[i]]), v += d[b[i]];
        v += d[b[0]];
        r = r < v ? r : v;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            b[l++] = i;
            f(l--);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0, j = 0; i < n; i++) {
        char s[101];
        scanf("%s", s);
        while (s[++j]) if (s[j] != s[j - 1]) d[i]++;
        a[i] = (s[0] - 48) * 10 + s[j - 1] - 48;
        j = 0;
    }
    f(0);
    printf("%d", r);
}
