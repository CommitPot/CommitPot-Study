#include <stdio.h>

int main() {
    int n, max = 0, max1 = 0, arr[100000], dp[100000] = {1}, dp1[100000] = {1};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
        if (arr[i] <= arr[i - 1]) dp1[i] = dp1[i - 1] + 1;
        else dp1[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (max < dp[i]) max = dp[i];
        if (max1 < dp1[i]) max1 = dp1[i];
    }
    printf("%d", max > max1 ? max : max1);
    return 0;
}