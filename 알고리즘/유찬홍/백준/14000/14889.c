#include <stdio.h>
#include <stdlib.h>

int n, r = 1e9, m[21][21], v[11];

void f(int l, int k) {
    if (l == n / 2) {
        int s = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                s += m[v[i]][v[j]] + m[v[j]][v[i]];
            }
        }
        int w[11];
        for (int i = 1, o = 0, p = 0; i <= n; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (v[j] == i) p = 1;
            }
            if (!p) w[o++] = i;
            p = 0;
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                s -= m[w[i]][w[j]] + m[w[j]][w[i]];
            }
        }
        r = r < abs(0 - s) ? r : abs(0 - s);
        return;
    }
    for (int i = k + 1; i <= n; i++) {
        v[l] = i;
        f(l + 1, i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    f(0, 0);
    printf("%d", r);
}
