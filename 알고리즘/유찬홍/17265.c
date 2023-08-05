#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int e(char op, int pre, int now) {
    now -= 48;
    switch (op) {
        case '+':
            return pre + now;
        case '-':
            return pre - now;
        case '*':
            return pre * now;
    }
}


int main() {
    int n, dp[5][5] = {0}, dp1[5][5] = {0};
    char arr[5][5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) continue;
            if (!i || !j) {
                if (!i && !j) dp[0][0] = dp1[0][0] = arr[0][0] - 48;
                else if (!i) dp[i][j] = dp1[i][j] = e(arr[i][j - 1], dp[i][j - 2], arr[i][j]);
                else dp[i][j] = dp1[i][j] = e(arr[i - 1][j], dp[i - 2][j], arr[i][j]);
            } else if (i == 1 || j == 1) {
                if (i == 1 && j == 1) {
                    dp[i][j] = max(e(arr[i][j - 1], dp[i - 1][j - 1], arr[i][j]),
                                   e(arr[i - 1][j], dp[i - 1][j - 1], arr[i][j]));
                    dp1[i][j] = min(e(arr[i][j - 1], dp1[i - 1][j - 1], arr[i][j]),
                                    e(arr[i - 1][j], dp1[i - 1][j - 1], arr[i][j]));
                } else if (i == 1) {
                    dp[i][j] = max(e(arr[i][j - 1], dp[i][j - 2], arr[i][j]),
                                   max(e(arr[i][j - 1], dp[i - 1][j - 1], arr[i][j]),
                                       e(arr[i - 1][j], dp[i - 1][j - 1], arr[i][j])));
                    dp1[i][j] = min(e(arr[i][j - 1], dp1[i][j - 2], arr[i][j]),
                                    min(e(arr[i][j - 1], dp1[i - 1][j - 1], arr[i][j]),
                                        e(arr[i - 1][j], dp1[i - 1][j - 1], arr[i][j])));
                } else {
                    dp[i][j] = max(e(arr[i - 1][j], dp[i - 2][j], arr[i][j]),
                                   max(e(arr[i][j - 1], dp[i - 1][j - 1], arr[i][j]),
                                       e(arr[i - 1][j], dp[i - 1][j - 1], arr[i][j])));
                    dp1[i][j] = min(e(arr[i - 1][j], dp1[i - 2][j], arr[i][j]),
                                    min(e(arr[i][j - 1], dp1[i - 1][j - 1], arr[i][j]),
                                        e(arr[i - 1][j], dp1[i - 1][j - 1], arr[i][j])));
                }
            } else {
                dp[i][j] = max(e(arr[i][j - 1], dp[i][j - 2], arr[i][j]),
                               max(e(arr[i - 1][j], dp[i - 2][j], arr[i][j]),
                                   max(e(arr[i][j - 1], dp[i - 1][j - 1], arr[i][j]),
                                       e(arr[i - 1][j], dp[i - 1][j - 1], arr[i][j]))));
                dp1[i][j] = min(e(arr[i][j - 1], dp1[i][j - 2], arr[i][j]),
                                min(e(arr[i - 1][j], dp1[i - 2][j], arr[i][j]),
                                    min(e(arr[i][j - 1], dp1[i - 1][j - 1], arr[i][j]),
                                        e(arr[i - 1][j], dp1[i - 1][j - 1], arr[i][j]))));
            }
        }
    }
    printf("%d %d", dp[n - 1][n - 1], dp1[n - 1][n - 1]);
}
