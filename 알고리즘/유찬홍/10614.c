#include <stdio.h>

int main() {
    int n, m, k, arr[16][16] = {0};
    scanf("%d %d %d", &n, &m, &k);
    int n1 = k ? k % m == 0 ? k / m : k / m + 1 : n;
    int m1 = k % m == 0 ? m : k % m;
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= m1; j++) {
            if (i == 1) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    for (int i = n1; i <= n; i++) {
        for (int j = m1; j <= m; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    printf("%d", arr[n][m]);
}
