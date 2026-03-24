#include <stdio.h>

int m(int a, int b, int c) { return a < b ? c ? a : b : c ? b : a; }

int main() {
    int n, c[2] = {}, r = 0;
    char s[300001];
    scanf("%d %s", &n, s);
    c[1]++;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1]) c[1]++;
        else c[0] = c[1], c[1] = 1;
        r = m(m(c[0], c[1], 1) * 2, r, 0);
    }
    printf("%d", r);
}
