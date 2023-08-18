#include <stdio.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

int main() {
    int a, b, c, v, e, arr[101][101];
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            arr[i][j] = i == j ? 0 : 1e9;
        }
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (arr[a][b] > c) arr[a][b] = c;
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            printf("%d ", arr[i][j] == 1e9 ? 0 : arr[i][j]);
        }
        printf("\n");
    }
}
