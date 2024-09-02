#include <stdio.h>

int n, dp[5000][5001];
char s[5001];

int min(int a, int b) { return a > b ? b : a; }

int f(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r]) return dp[l][r];
    return dp[l][r] = s[l] == s[r] ? f(l + 1, r - 1) : min(f(l + 1, r), f(l, r - 1)) + 1;
}

int main() {
    scanf("%d %s", &n, s);
    printf("%d", f(0, n - 1));
}
