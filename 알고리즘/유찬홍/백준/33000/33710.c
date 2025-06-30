#include <stdio.h>

int max(int a, int b) { return a < b ? b : a; }

int f(char *s, int v, int n, int m, int p) {
    if (!m || v == n - 1) return p;
    int r = 0;
    for (int i = v + 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j] && s[i] != 'X') {
                r = max(r, f(s, j, n, m - 1, p + j - i + 1));
            }
        }
    }
    return r + (r ? 0 : p);
}

int main() {
    int n, m;
    char s[101];
    scanf("%d %d %s", &n, &m, s);
    printf("%d", n - f(s, -1, n, m, 0));
}
