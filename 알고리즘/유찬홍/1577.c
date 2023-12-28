#include <stdio.h>

int main() {
    int n, m, k, a, b, c, d, arr1[2][101][101];
    long long int arr[101][101] = {0};
    scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a + b < c + d) {
            if (c - a > d - b) arr1[0][d][c] = 1;
            else arr1[1][d][c] = 1;
        } else {
            if (a - c > b - d) arr1[0][b][a] = 1;
            else arr1[1][b][a] = 1;
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (!i && !j) arr[0][0] = 1;
            else {
                if (arr1[0][i][j] && arr1[1][i][j]) arr[i][j] = 0;
                else {
                    if (arr1[0][i][j]) arr[i][j] = i ? arr[i - 1][j] : 0;
                    else if (arr1[1][i][j]) arr[i][j] = j ? arr[i][j - 1] : 0;
                    else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }
            }
        }
    }
    printf("%lld", arr[m][n]);
}
