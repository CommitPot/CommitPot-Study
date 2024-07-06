#include <stdio.h>

int s[101], dp[101][3][3];

int f(int l, int a, int b) {
    if (l == 0) return 1;
    if (dp[l][a][b] > -1) return dp[l][a][b];
    dp[l][a][b] = 0;
    if (s[l] != -1) {
        if (!(a == s[l] && b == s[l])) return dp[l][a][b] = f(l - 1, s[l], a);
        return 0;
    }
    if (!(a == 0 && b == 0)) dp[l][a][b] += f(l - 1, 0, a);
    if (!(a == 1 && b == 1)) dp[l][a][b] += f(l - 1, 1, a);
    if (!(a == 2 && b == 2)) dp[l][a][b] += f(l - 1, 2, a);
    return dp[l][a][b] %= 10000;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 101; i++) s[i] = -1;
    while (k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        s[a] = b - 1;
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 3; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
    int x = 0;
    if (s[n] > -1 && s[n - 1] > -1) x = f(n - 2, s[n - 1], s[n]);
    else if (s[n] > -1) x = (x + f(n - 2, 0, s[n]) + f(n - 2, 1, s[n]) + f(n - 2, 2, s[n])) % 10000;
    else if (s[n - 1] > -1) x = (x + f(n - 2, s[n - 1], 0) + f(n - 2, s[n - 1], 1) + f(n - 2, s[n - 1], 2)) % 10000;
    else
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                x = (x + f(n - 2, s[n - 1] > -1 ? s[n - 1] : i, s[n] > -1 ? s[n] : j)) % 10000;
            }
        }
    printf("%d", x);
}
