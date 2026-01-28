#include <stdio.h>

int main() {
    int n;
    char s[20][21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) s[i][j] = !i || i == n - 1 ? '*' : 32;
        s[i][0] = s[i][n - 1] = s[i][i] = s[i][n - 1 - i] = '*';
        s[i][n] = 0;
    }
    for (int i = 0; i < n; i++) printf("%s\n", s[i]);
}
