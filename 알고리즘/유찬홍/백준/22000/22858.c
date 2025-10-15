#include <stdio.h>

int main() {
    int n, k, a[10001], b[2][10001];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &b[0][i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            b[~i & 1][a[j]] = b[i & 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[k & 1][i]);
    }
}
