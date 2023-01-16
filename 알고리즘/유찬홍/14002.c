#include<stdio.h>

int main() {
    int n, arr[1000], dp[1000] = {0,}, dp1[1000], result = 0, d = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int c = arr[i];
        for (int j = 0; j < i; j++) {
            if (c > arr[j]) dp[i] = dp[i] > dp[j] ? dp[i] : dp[j];
        }
        dp[i]++;
        if (result < dp[i]) result = dp[i];
    }
    printf("%d\n", result);
    for (int i = n - 1; i >= 0; i--) {
        if (result == dp[i]) {
            dp1[d++] = arr[i];
            result--;
        }
    }
    for (int i = d - 1; i >= 0; i--) {
        printf("%d ", dp1[i]);
    }
}