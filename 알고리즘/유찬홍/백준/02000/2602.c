#include <stdio.h>

int main() {
    int r[2][21][101] = {}, l = -1, sl = -1, c = 0;
    char s[21], a[101], b[101];
    scanf("%s %s %s", s, a, b);
    while (s[++sl]);
    while (b[++l]);
    for (int i = 0; i < l; i++) {
        if (a[i] == s[0]) r[0][0][i] = 1;
        if (b[i] == s[0]) r[1][0][i] = 1;
    }
    for (int i = 1; i < sl; i++) {
        for (int j = l - 1; j >= 0; j--) {
            if (a[j] == s[i]) {
                for (int k = j - 1; k >= 0; k--) {
                    if (b[k] == s[i - 1]) r[0][i][j] += r[1][i - 1][k];
                }
            }
            if (b[j] == s[i]) {
                for (int k = j - 1; k >= 0; k--) {
                    if (a[k] == s[i - 1]) r[1][i][j] += r[0][i - 1][k];
                }
            }
        }
    }
    for (int j = 0; j < l; j++) {
        c += r[0][sl - 1][j] + r[1][sl - 1][j];
    }
    printf("%d", c);
}
