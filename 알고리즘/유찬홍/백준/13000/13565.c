#include <stdio.h>

int n, m, arr[1001][1001];

int dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return 0;
    if (!arr[x][y]) {
        arr[x][y] = 2;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return 0;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        dfs(1, i);
    }
    for (int i = 1; i <= m; i++) {
        if (arr[n][i] == 2) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}