#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, a, b, arr[302][302] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = m - (a + b) < 0 ? 0 : m - (a + b);
    }
    for (int i = 1; i <= 301; i++) {
        for (int j = 1; j <= 301; j++) {
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    printf("%d", arr[301][301]);
}
