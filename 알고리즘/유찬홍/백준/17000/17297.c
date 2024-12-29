#include <stdio.h>

int dp[40] = {0, 5, 13};

char f(int n, int k, int t) {
    if (n-- < 3) return " Messi Gimossi "[t];
    if (dp[n] >= t) return f(n, dp[n + 1], t);
    return f(n, k - dp[n] - 1, t - dp[n] - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int i = 3;
    do dp[i] = dp[i - 1] + dp[i - 2] + 1;
    while (dp[i++] < n);
    i = n < 6 ? 1 : n < 14 ? 2 : i - 1;
    char x = f(i, dp[i], n);
    if (x == ' ') printf("Messi Messi Gimossi");
    else printf("%c", x);
}
