#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int dp[1001][1001] = {0}, c = 0;
char arr[1001], arr1[1001], arr2[1001];

int main() {
    scanf("%s %s", arr, arr1);
    int len = strlen(arr), len1 = strlen(arr1);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len1; j++) {
            if (arr[i - 1] == arr1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d", dp[len][len1]);
    if (dp[len][len1]) {
        int i = len;
        int j = len1;
        while (dp[i][j] != 0) {
            if (dp[i - 1][j] == dp[i][j]) i--;
            else if (dp[i][j - 1] == dp[i][j]) j--;
            else {
                if (dp[i][j] == dp[i - 1][j - 1] + 1) arr2[c++] = arr[i - 1];
                i--;
                j--;
            }
        }
        printf("\n");
        for (int k = c - 1; k >= 0; k--) {
            printf("%c", arr2[k]);
        }
    }
    return 0;
}