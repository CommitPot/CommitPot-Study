#include <stdio.h>

int n, m, w = 0, v = 0, arr[501][501];

int dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return 0;
    if (arr[x][y]) {
        arr[x][y] = 0;
        v++;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return 1;
    }
    return 0;
}


int main() {
    int count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]) {
                count++;
                dfs(i, j);
                if (w < v) w = v;
            }
            v = 0;
        }
    }
    printf("%d\n%d", count, w);
}