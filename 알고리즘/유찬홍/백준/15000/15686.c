#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) { return x < y ? x : y; }

int n, m, s, a[2501], b[13];

int f(int x) {
    if (s > m) return 1e9;
    if (s == m) {
        int c[2501] = {};
        for (int i = 0; i < n * n; i++) c[i] = 1e9;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n * n; j++) {
                int k = j / n, l = (j + n) % n, o = b[i] / n, p = (b[i] + n) % n;
                if (a[j] == 1) c[j] = min(c[j], abs(k - o) + abs(l - p));
            }
        }
        int p = 0;
        for (int i = 0; i < n * n; i++) {
            if (c[i] == 1e9) c[i] = 0;
            p += c[i];
        }
        return p;
    }
    int r = 1e9;
    for (int i = x; i < n * n; i++) {
        if (a[i] == 2) {
            b[s] = i;
            s++;
            r = min(r, f(i + 1));
            s--;
        }
    }
    return r;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", f(0));
}
