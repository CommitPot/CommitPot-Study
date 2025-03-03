#include <stdio.h>
#include <string.h>

int f(const char *t, const char *s, int k, int a) {
    if (!*t) return k;
    if (!*s || *t != *s) return -1;
    return f(t + 1, s + (a ? 1 : -1), k + 1, a);
}

int main() {
    int n, a = 0, b;
    char p[2][101], s[101];
    scanf("%d %s", &n, p[0]);
    while (p[0][a++] != '*');
    b = a;
    do p[1][b - a] = p[0][b]; while (p[0][b++]);
    a--;
    p[0][a] = p[1][b - a] = 0;
    b -= a + 2;
    for (int i = 0, j = b - 1; i < j; i++, j--) {
        char t = p[1][i];
        p[1][i] = p[1][j];
        p[1][j] = t;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        int x = f(p[0], s, -1, 1);
        if (x < 0) {
            printf("NE\n");
            continue;
        }
        s[x] = 0;
        printf("%s\n", f(p[1], &s[l - 1], 0, 0) > 0 ? "DA" : "NE");
    }
}
