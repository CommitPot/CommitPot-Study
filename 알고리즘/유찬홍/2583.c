#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int n, m, k, arr[101][101] = {0}, wh = 0;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return;
    if (!arr[x][y]) {
        wh++;
        arr[x][y] = 1;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return;
    }
    return;
}

int main() {
    int a, b, c, d, count = 0, arr1[100];
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int j = b; j < d; j++) {
            for (int l = a; l < c; l++) {
                arr[j][l] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!arr[i][j]) {
                dfs(i, j);
                arr1[count++] = wh;
                wh = 0;
            }
        }
    }
    printf("%d\n", count);
    qsort(arr1, count, 4, comp);
    for (int i = 0; i < count; i++) {
        printf("%d ", arr1[i]);
    }
}