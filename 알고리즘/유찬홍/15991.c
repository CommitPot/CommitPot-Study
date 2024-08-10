#include <stdio.h>

#define k 1000000009

int main() {
    int n, m, dp[100001] = {1, 1, 2, 2, 3, 3};
    for (int i = 6; i < 100001; i++) dp[i] = ((dp[i - 2] + dp[i - 4]) % k + dp[i - 6]) % k;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        printf("%d\n", dp[m]);
    }
}
