#include <stdio.h>

int main() {
    int n, arr[101][101];
    long long int vis[101][101] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
    vis[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k < i; k++) if (arr[i - k][j] == k) vis[i][j] += vis[i - k][j];
            for (int k = 1; k < j; k++) if (arr[i][j - k] == k) vis[i][j] += vis[i][j - k];
        }
    }
    printf("%lld", vis[n][n]);
}
