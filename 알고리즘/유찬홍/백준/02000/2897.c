#include <stdio.h>

int main() {
    int n, m, r[5] = {};
    char a[51][51];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int v = 0;
            if (a[i][j] == 'X') v++;
            if (a[i - 1][j] == 'X') v++;
            if (a[i][j - 1] == 'X') v++;
            if (a[i - 1][j - 1] == 'X') v++;
            if (a[i][j] == '#' || a[i - 1][j] == '#' || a[i][j - 1] == '#' || a[i - 1][j - 1] == '#') continue;
            r[v]++;
        }
    }
    for (int i = 0; i < 5; i++) printf("%d\n", r[i]);
}
