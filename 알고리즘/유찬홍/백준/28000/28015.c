#include <stdio.h>

int main() {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int c[2] = {};
        if (a) c[a - 1]++;
        for (int j = 1; j < m; j++) {
            scanf("%d", &b);
            if (b && a != b) c[b - 1]++;
            if (!b || j == m - 1) {
                if (c[0] || c[1]) r += c[0] == c[1] ? c[0] + 1 : c[0] < c[1] ? c[1] : c[0];
                c[0] = c[1] = 0;
            }
            a = b;
        }
    }
    printf("%d", r);
}
