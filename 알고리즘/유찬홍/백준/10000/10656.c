#include <stdio.h>

int main() {
    int n, m, s[2500][2], r = 0;
    char a[52][53];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", &a[i][1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((a[i][j - 1] == '#' || j == 1) && a[i][j] == '.' && a[i][j + 1] == '.' && a[i][j + 2] == '.') {
                s[r][0] = i;
                s[r][1] = j;
                r++;
            } else if ((a[i - 1][j] == '#' || i == 1) && a[i][j] == '.' && a[i + 1][j] == '.' && a[i + 2][j] == '.') {
                s[r][0] = i;
                s[r][1] = j;
                r++;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d %d\n", s[i][0], s[i][1]);
    }
}
