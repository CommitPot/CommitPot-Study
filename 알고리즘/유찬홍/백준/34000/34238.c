#include <stdio.h>

int f(char s[100][101], int n, int m, int h, int w, int c, int p) {
    if (c == 2) return p / 10 == p % 10;
    int a[] = {-1, 0, 1, 1, 1, 0, -1, -1}, b[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int r = 0;
    for (int i = 0; i < 8; i++) {
        if (h + a[i] < 0 || h + a[i] >= n || w + b[i] < 0 || w + b[i] >= m) continue;
        if ((!c && s[h + a[i]][w + b[i]] != 'O') || (c == 1 && s[h + a[i]][w + b[i]] != 'X')) continue;
        r += f(s, n, m, h + a[i], w + b[i], c + 1, p * 10 + i);
    }
    return r;
}

int main() {
    int n, m, r = 0;
    char s[100][101];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'F') r += f(s, n, m, i, j, 0, 0);
        }
    }
    printf("%d", r);
}
