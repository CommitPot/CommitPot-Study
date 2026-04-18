#include <stdio.h>
#include <string.h>

int dp[1001][1001];
char a[1001], b[1001];

int min(int c, int d) { return c < d ? c : d; }

int f(int c, int d) {
    if (dp[c][d] >= 0) return dp[c][d];
    if (!b[d]) return dp[c][d] = (int) strlen(a) - c;
    if (!a[c]) return dp[c][d] = (int) strlen(b) - d;
    if (a[c] == b[d]) return dp[c][d] = f(c + 1, d + 1);
    return dp[c][d] = min(min(f(c + 1, d), f(c, d + 1)), f(c + 1, d + 1)) + 1;
}

int main() {
    scanf("%s %s", a, b);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(0, 0));
}
