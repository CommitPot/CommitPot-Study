#include <stdio.h>

int main() {
    int n, m, a, b, rs = 1000000000, idx, arr[101][101];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] > arr[i][k] + arr[j][i]) {
                    arr[j][k] = arr[i][k] + arr[j][i];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) sum += arr[i][j];
        if (rs > sum) {
            rs = sum;
            idx = i;
        }
    }
    printf("%d", idx);
}
