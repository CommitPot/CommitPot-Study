#include <stdio.h>
#include <memory.h>

int n, a[5001], dp[5001][5001];

int min(int x, int y) { return x > y ? y : x; }

int f(int s, int e) {
    if (s >= e) return 0;
    if (dp[s][e] > -1) return dp[s][e];
    if (a[s] == a[e]) return dp[s][e] = f(s + 1, e - 1);
    return dp[s][e] = min(f(s + 1, e), f(s, e - 1)) + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(0, n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

        }
    }
}
