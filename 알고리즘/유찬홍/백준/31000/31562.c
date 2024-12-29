#include <stdio.h>
#define k r[c[0] - 65][c[2] - 65][c[4] - 65]

int main() {
    int n, m, r[7][7][7] = {};
    char s[1000][31];
    scanf("%d %d", &n, &m);
    for (int i = 1, b; i <= n; i++) {
        char c[15];
        scanf("%d %s %[^\n] ", &b, s[i], c);
        k = k ? -1 : i;
    }
    while (m--) {
        char c[5];
        scanf(" %[^\n]", c);
        if (k > 0) printf("%s\n", s[k]);
        else printf("%c\n", k ? '?' : '!');
    }
}
