#include <stdio.h>

int main() {
    int dp[41] = {1,}, l = 0;
    char s[41];
    scanf("%s", s);
    while (s[l]) s[l++] -= 48;
    for (int i = 1; i < l; i++) {
        if (s[i]) dp[i] = dp[i - 1];
        if ((s[i - 1] && s[i - 1] < 3) || (s[i - 1] == 3 && s[i] < 5)) dp[i] += i > 1 ? dp[i - 2] : 1;
    }
    printf("%d", dp[l - 1]);
}
