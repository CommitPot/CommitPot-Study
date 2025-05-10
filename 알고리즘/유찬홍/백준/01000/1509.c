#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    char s[2502];
    bool p[2501][2501] = {};
    short dp[2501] = {};
    scanf("%s", &s[1]);
    int l = strlen(&s[1]) + 1;
    for (int i = 1; i < l; i++) {
        int j = i - 1, k = i + 1;
        while (j && k < l && s[j] == s[k]) {
            p[j][k] = 1;
            j--, k++;
        }
        j = i - 1, k = i;
        while (j && k < l && s[j] == s[k]) {
            p[j][k] = 1;
            j--, k++;
        }
    }
    for (int i = 1; i < l; i++) p[i][i] = 1;
    for (int i = 1; i < l; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j < i; j++) {
            if (p[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    printf("%d", dp[l - 1]);
}
