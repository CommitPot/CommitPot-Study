#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int dp[41][41] = {0}, c = 0;
    char arr[41], arr1[41], arr2[41];
    scanf("%s %s", arr, arr1);
    int len = strlen(arr), len1 = strlen(arr1);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len1; j++) {
            if (arr[i - 1] == arr1[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    while (dp[len][len1] != 0) {
        if (dp[len - 1][len1] == dp[len][len1]) len--;
        else if (dp[len][len1 - 1] == dp[len][len1]) len1--;
        else {
            if (dp[len][len1] == dp[len - 1][len1 - 1] + 1) arr2[c++] = arr[len - 1];
            len--;
            len1--;
        }
    }
    for (int k = c - 1; k >= 0; k--) {
        printf("%c", arr2[k]);
    }
}
