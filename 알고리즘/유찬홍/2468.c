#include <stdio.h>

int n, w = 0, arr[101][101], arr1[101][101];

int dfs(int x, int y, int h) {
    if (!x || !y || x > n || y > n) return 0;
    if (arr[x][y] > h) {
        arr[x][y] = 0;
        dfs(x - 1, y, h);
        dfs(x + 1, y, h);
        dfs(x, y + 1, h);
        dfs(x, y - 1, h);
        return 1;
    }
    return 0;
}


int main() {
    int count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            arr1[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] > i) {
                    count++;
                    dfs(j, k, i);
                }
            }
        }
        if (count > w) w = count;
        count = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = arr1[j][k];
            }
        }
    }
    printf("%d", w);
}