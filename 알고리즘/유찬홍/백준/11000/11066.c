#include <stdio.h>

int a[501], dp[501][501];

int min(int x, int y) { return x > y ? y : x; }

int f(int l, int r) {
    if (l == r) return dp[l][r] = a[l] - a[l - 1];
    if (dp[l][r] >= 0) return dp[l][r];
    dp[l][r] = 1e9;
    for (int i = l; i < r; i++) {
        int li = f(l, i), ri = f(i + 1, r);
        int c = 0;
        if (l < i) c += a[i] - a[l - 1];
        if (i + 1 < r) c += a[r] - a[i];
        dp[l][r] = min(dp[l][r], li + ri + c);
    }
    return dp[l][r];
}

int main() {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
            for (int j = i; j <= k; j++)
                dp[i][j] = -1;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        printf("%d\n", f(1, k));
    }
}
