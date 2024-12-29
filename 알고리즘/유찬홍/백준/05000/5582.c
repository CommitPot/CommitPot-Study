#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int dp[4001][4001] = {0}, rs = 0;
    char arr[4001], arr1[4001];
    scanf("%s %s", arr, arr1);
    int len = strlen(arr), len1 = strlen(arr1);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len1; j++) {
            if (arr[i - 1] == arr1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = 0;
            rs = max(rs, dp[i][j]);
        }
    }
    printf("%d", rs);
    return 0;
}