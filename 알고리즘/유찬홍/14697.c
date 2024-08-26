#include <stdio.h>

int dp[301], g[3];

int f(int v) {
    if (v <= 0) return !v;
    if (~dp[v]) return dp[v];
    return dp[v] = f(v - g[0]) | f(v - g[1]) | f(v - g[2]);
}

int main() {
    int a;
    for (int i = 0; i < 3; i++) scanf("%d", &g[i]);
    scanf("%d", &a);
    for (int i = 0; i <= a; i++) dp[i] = -1;
    printf("%d", f(a));
}
