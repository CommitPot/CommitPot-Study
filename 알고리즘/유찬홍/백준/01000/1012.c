#include <stdio.h>

int n, m, k, arr[51][51] = {0};

int dfs(int x, int y) {
    if (!x || !y || x > m || y > n) return 0;
    if (arr[x][y]) {
        arr[x][y] = 0;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return 1;
    }
    return 0;
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int count = 0;
        scanf("%d %d %d", &n, &m, &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d %d", &a, &b);
            arr[b + 1][a + 1] = 1;
        }
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= m; l++) {
                if (arr[l][j]) {
                    count++;
                    dfs(l, j);
                }
            }
        }
        printf("%d\n", count);
        for (int j = 0; j <= 50; j++) {
            for (int l = 0; l <= 50; l++) {
                arr[j][l] = 0;
            }
        }
    }
}