#include <stdio.h>
#include <string.h>

int max(int a, int b, int c) { return a >= b && a >= c ? a : b > c ? b : c; }

int dp[101][101][101] = {0};
char arr[101], arr1[101], arr2[101];

int main() {
    scanf("%s %s %s", arr, arr1, arr2);
    int len = strlen(arr), len1 = strlen(arr1), len2 = strlen(arr2);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len1; j++) {
            for (int k = 1; k <= len2; ++k) {
                if (arr[i - 1] == arr1[j - 1] && arr[i - 1]== arr2[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
            }
        }
    }
    printf("%d", dp[len][len1][len2]);
    return 0;
}