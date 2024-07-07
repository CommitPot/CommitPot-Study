#include <stdio.h>

int dp[100001][5][5], d[] = {0, 3, 4, 1, 2};
char s[200001];

int min(int a, int b) { return a > b ? b : a; }

int f(int k, int l, int r) {
    if (s[k] == 48) return 0;
    if (k && l == r) return 1e9;
    if (dp[k / 2][l][r]) return dp[k / 2][l][r];
    return dp[k / 2][l][r] = min(f(k + 2, s[k] - 48, r) + (!l ? 2 : l == s[k] - 48 ? 1 : l == d[s[k] - 48] ? 4 : 3),
                                 f(k + 2, l, s[k] - 48) + (!r ? 2 : r == s[k] - 48 ? 1 : r == d[s[k] - 48] ? 4 : 3));
}

int main() {
    scanf("%[^\n]", s);
    printf("%d", f(0, 0, 0));
}
