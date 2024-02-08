#include <stdio.h>

int main() {
    int n, arr[101][101], vis[10001] = {0}, c = 0, d = 0;
    scanf("%d", &n);
    int rs = (n * n * n + n) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (vis[arr[i][j]]) rs = 0;
            vis[arr[i][j]]++;
            if (i == j) c += arr[i][j];
            if (i + j == n - 1) d += arr[i][j];
        }
    }
    if (!rs || c != rs || d != rs) {
        printf("FALSE");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            a += arr[i][j];
            b += arr[j][i];
        }
        if (rs != a || rs != b) {
            printf("FALSE");
            return 0;
        }
    }
    printf("TRUE");
}
