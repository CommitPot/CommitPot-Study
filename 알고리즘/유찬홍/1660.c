#include <stdio.h>

int main() {
    int n, arr[121] = {0, 1}, dp[300001];
    scanf("%d", &n);
    for (int i = 2; i <= 120; i++) {
        arr[i] = arr[i - 1] + i;
    }
    for (int i = 2; i <= 120; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = 1e9;
    }
    for (int i = 1; i <= 120; i++) {
        dp[arr[i]] = 1;
    }
    for (int i = 1; i <= 120; i++) {
        for (int j = arr[i]; j <= n; j++) {
            if (dp[j] > dp[j - arr[i]] + 1) {
                dp[j] = dp[j - arr[i]] + 1;
            }
        }
    }
    printf("%d", dp[n]);
}
