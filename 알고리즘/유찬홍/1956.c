#include <stdio.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)
int v, e, min = 1e9, arr[401][401];

int main() {
    int a, b, c;
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            arr[i][j] = i == j ? 0 : 1e9;
        }
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
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
            if (i == j) continue;
            min = min(min, arr[i][j] + arr[j][i]);
        }
    }
    printf("%d", min == 1e9 ? -1 : min);
}
