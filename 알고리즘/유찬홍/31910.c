#include <stdio.h>
#define ll long long

ll max(ll a, ll b) { return a > b ? a : b; }

ll f(ll a, char b) { return a << 1 | b - 48; }

int main() {
    int n;
    char m[30][61];
    ll dp[30][60] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(" %[^\n]", m[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j += 2) {
            if (!i && !j) dp[i][j] = m[i][j] - 48;
            else if (!i || !j) dp[i][j] = f(i ? dp[i - 1][j] : dp[i][j - 2], m[i][j]);
            else dp[i][j] = f(max(dp[i][j - 2], dp[i - 1][j]), m[i][j]);
        }
    }
    printf("%lld", dp[n - 1][n * 2 - 2]);
}
