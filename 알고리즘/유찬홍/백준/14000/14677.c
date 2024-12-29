#include <stdio.h>
#include <string.h>

int n, dp[1500][1500];
char s[1501], d[] = "BLD";

int max(int a, int b) { return a > b ? a : b; }

int f(int v, int a, int l, int r) {
    if (l > r) return v;
    if (dp[l][r] > -1) return dp[l][r];
    int x = 0;
    if (s[l] == d[a]) x = max(x, f(v + 1, (a + 1) % 3, l + 1, r));
    if (s[r] == d[a]) x = max(x, f(v + 1, (a + 1) % 3, l, r - 1));
    return dp[l][r] = x ? x : v;
}

int main() {
    scanf("%d %s", &n, s);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(0, 0, 0, n * 3 - 1));
}
