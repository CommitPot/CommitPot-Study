#include <stdio.h>

int dp[21][21][21] = {0};

int w(int a, int b, int c) {
    if (a < 1 || b < 1 || c < 1) return 1;
    if (a > 20 || b > 20 || c > 20) return 1048576;
    if (dp[a][b][c]) return dp[a][b][c];
    if (a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    while (!(a == -1 && b == -1 && c == -1)) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
        scanf("%d %d %d", &a, &b, &c);
    }
}
