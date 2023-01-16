#include<stdio.h>

int main() {
    int n, arr[1000], dp[1000] = {0,}, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int c = arr[i];
        for (int j = 0; j < i; j++) {
            if (c < arr[j]) dp[i] = dp[i] > dp[j] ? dp[i] : dp[j];
        }
        dp[i]++;
        if (result < dp[i]) result = dp[i];
    }
    printf("%d", result);
}