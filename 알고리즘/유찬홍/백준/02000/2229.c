#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1001];

int max(int a, int b) { return a > b ? a : b; }

int f(int *a, int n) {
    if (dp[n] > -1) return dp[n];
    int r = 0, c = -1, d = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > c) c = a[i];
        if (a[i] < d) d = a[i];
        r = max(r, f(a, i) + c - d);
    }
    return dp[n] = r;
}

int main() {
    int n, a[1001];
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d", f(a, n));
}
