#include <stdio.h>

int main() {
    int n, k, m = 1e9, arr[201][201] = {1};
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            arr[i][j] = !j ? 1 : (arr[i - 1][j] + arr[i][j - 1]) % m;
        }
    }
    printf("%d", arr[k][n]);
}
