#include <stdio.h>

int main() {
    int n, rs = 0, arr[1000], dp[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) dp[i] = dp[i] > dp[j] ? dp[i] : dp[j];
        }
        dp[i]++;
        if (rs < dp[i]) rs = dp[i];
    }
    printf("%d", rs);
    return 0;
}