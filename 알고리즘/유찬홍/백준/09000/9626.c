#include <stdio.h>

int main() {
    char s[21][21], p[10][11];
    int n, m, u, l, r, d;
    scanf("%d %d %d %d %d %d", &n, &m, &u, &l, &r, &d);
    for (int i = 0; i < n; i++) scanf("%s", p[i]);
    for (int i = 0; i < n + u + d; i++) {
        for (int j = 0; j < m + l + r; j++) {
            s[i][j] = i + j & 1 ? '.' : '#';
        }
    }
    for (int i = u; i < n + u; i++) {
        for (int j = l; j < l + m; j++) {
            s[i][j] = p[i - u][j - l];
        }
    }
    for (int i = 0; i < n + u + d; i++) {
        for (int j = 0; j < m + l + r; j++) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}
