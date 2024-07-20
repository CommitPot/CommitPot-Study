#include <stdio.h>
#include <string.h>

#define ll long long
ll dp[11][2001];

ll f(int n, int m) {
    if (!n) return m > 0;
    if (dp[n][m] > -1) return dp[n][m];
    ll x = 0;
    for (int i = m / 2; i >= 1; i--) x += f(n - 1, i);
    return dp[n][m] = x;
}

int main() {
    int n, m, t;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        ll s = 0;
        while (m--) s += f(n - 1, m + 1);
        printf("%lld\n", s);
    }
}
