#include <stdio.h>

int main() {
    int n, m;
    long long int arr[1001][1001] = {0};
    scanf("%d %d", &m, &n);
    arr[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1] + arr[i - 1][j - 1]) % 1000000007;
        }
    }
    printf("%lld", arr[n][m]);
}
