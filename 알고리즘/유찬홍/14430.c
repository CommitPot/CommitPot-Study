#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, big = 0, arr[301][301] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    printf("%d", arr[n][m]);
}
