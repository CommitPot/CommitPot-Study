#include <stdio.h>

int n, m, arr[251][251] = {0};

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y]) {
        arr[x][y] = 0;
        dfs(x + 1, y);
        dfs(x + 1, y + 1);
        dfs(x + 1, y - 1);
        dfs(x, y + 1);
        dfs(x, y - 1);
        dfs(x - 1, y);
        dfs(x - 1, y - 1);
        dfs(x - 1, y + 1);
        return;
    }
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
            if (arr[i][j]) dfs(i, j), count++;
        }
    }
    printf("%d", count);
    return 0;
}