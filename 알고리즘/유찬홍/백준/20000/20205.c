#include <stdio.h>

int main() {
    int n, k, arr[11][11];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= n; l++) {
                for (int m = 1; m <= k; m++) {
                    printf("%d ", arr[i][l]);
                }
            }
            printf("\n");
        }
    }
}
