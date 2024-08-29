#include <stdio.h>

int main() {
    int n, d[] = {0, 1, 0, -1};
    char s[2000][2001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 'O') continue;
            for (int k = 0; k < 4; k++) {
                int l = 1;
                while (1) {
                    int x = i + d[k] * l, y = j + d[3 - k] * l;
                    if (x < 0 || x >= n || y < 0 || y >= n || s[x][y] == 'O' || s[x][y] == 'X') break;
                    s[x][y] = '0';
                    l++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) s[i][j] = s[i][j] == 48 ? '.' : s[i][j] == '.' ? 'B' : s[i][j];
        printf("%s\n", s[i]);
    }
}
