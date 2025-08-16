#include <stdio.h>

int main() {
    int n, s, e, b = 0, c = 0;
    char a[2][51] = {};
    long long dp[51] = {0, 0, 1, 1};
    scanf("%d %d %d", &n, &s, &e);
    for (int i = 4; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2] + 1;
    for (long long i = n, j = 1; j != s;) {
        if (j + dp[i] >= s) a[0][b] = 'L', j++, i -= 2;
        else a[0][b] = 'R', j += dp[i] + 1, i--;
        b++;
    }
    for (long long i = n, j = 1; j != e;) {
        if (j + dp[i] >= e) a[1][c] = 'L', j++, i -= 2;
        else a[1][c] = 'R', j += dp[i] + 1, i--;
        c++;
    }
    n = 0;
    while (a[0][n] == a[1][n]) n++;
    for (int i = n; i < b; i++) printf("U");
    for (int i = n; i < c; i++) printf("%c", a[1][i]);
}
