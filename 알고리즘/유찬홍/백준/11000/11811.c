#include <stdio.h>

int main() {
    int n, a[1001][1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) x |= a[i][j];
        printf("%d ", x);
    }
}
