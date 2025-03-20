#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a[2][1001];
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (n == 2) {
        printf("1 1");
        return 0;
    }
    a[1][0] = abs(a[0][n - 1] - a[1][n - 1] + a[0][1]) / 2;
    a[1][1] = a[0][1] - a[1][0];
    printf("%d %d ", a[1][0], a[1][1]);
    for (int i = 2; i < n; i++) {
        a[1][i] = a[0][i] - a[0][i - 1] + a[1][i - 1];
        printf("%d ", a[1][i]);
    }
}
