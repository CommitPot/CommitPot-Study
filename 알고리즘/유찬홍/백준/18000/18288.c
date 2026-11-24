#include <stdio.h>
#include <string.h>

#define M 1000000007

int dp[100001][10][2][2];

int f(int n, int k, int a, int b, int c) {
    if (!n) return c && (k ? !(a % k) : !a);
    if (dp[n][a][b][c]) return dp[n][a][b][c];
    int x = f(n - 1, k, a, 1, 1);
    if (k) x = (x + f(n - 1, k, (a + 1) % k, 1, c)) % M;
    if (b) x += f(n - 1, k, a, 0, c);
    return dp[n][a][b][c] = x % M;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(dp, 0, sizeof(dp));
    printf("%d", f(n, k, 0, 1, 0));
}
