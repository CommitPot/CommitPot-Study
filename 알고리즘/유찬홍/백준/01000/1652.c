#include <stdio.h>

int main() {
    int n, r[2] = {}, a[101][101][2] = {};
    char s[101][101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        int k = 0, l = 0;
        for (int j = 1; j < n; j++) {
            if (s[i][j] != 'X' && s[i][j - 1] != 'X' && !a[i][j][0] && !a[i][j - 1][0]) {
                k++;
                int x = j - 1;
                while (s[i][x] != 'X' && x < n) a[i][x++][0] = 1;
            }
            if (s[j][i] != 'X' && s[j - 1][i] != 'X' && !a[j][i][1] && !a[j - 1][i][1]) {
                int x = j - 1;
                while (s[x][i] != 'X' && x < n) a[x++][i][1] = 1;
                l++;
            }
        }
        r[0] += k, r[1] += l;
    }
    printf("%d %d", r[0], r[1]);
}
