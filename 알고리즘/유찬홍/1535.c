#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, w[21], v[21], arr[21][101] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 101; j++) {
            if (j > w[i]) {
                arr[i][j] = max(arr[i - 1][j - w[i]] + v[i], arr[i - 1][j]);
            } else {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    printf("%d", arr[n][100]);
}
