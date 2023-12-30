#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, b = 0, arr[501][501];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!j) arr[i][j] += max(arr[i - 1][j], arr[i - 1][j + 1]);
            else if (j == m - 1) arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            else arr[i][j] += max(arr[i - 1][j - 1], max(arr[i - 1][j], arr[i - 1][j + 1]));
        }
    }
    for (int i = 0; i < m; i++) {
        if (b < arr[n - 1][i]) b = arr[n - 1][i];
    }
    printf("%d", b);
}
