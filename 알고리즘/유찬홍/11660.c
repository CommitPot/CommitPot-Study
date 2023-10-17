#include <stdio.h>

int main() {
    int n, m, arr[1025][1025] = {0}, a, b, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", arr[c][d] - arr[c][b - 1] - arr[a - 1][d] + arr[a - 1][b - 1]);
    }
}
