#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int x(char a, int b) { return a == '-' ? -b : b; }

int main() {
    int dp[200001];
    char s[200001];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        dp[i] = -2e9;
        if (!i) dp[i] = s[i] == '+' ? 10 : 1;
        if (i == 1 && s[0] == '+' && s[1] == '-') dp[i] = 11;
        if (i - 2 >= 0) {
            if (s[i] == '-') dp[i] = max(dp[i], dp[i - 2] + x(s[i - 1], 1));
            if (s[i] == '+') dp[i] = max(dp[i], dp[i - 2] + x(s[i - 1], 10));
        }
        if (i - 3 >= 0) {
            if (s[i - 1] == '+' && s[i] == '-') dp[i] = max(dp[i], dp[i - 3] + x(s[i - 2], 11));
        }
        if (!s[i + 1]) printf("%d", dp[i]);
    }
}
