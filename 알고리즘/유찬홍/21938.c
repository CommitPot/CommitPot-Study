#include <stdio.h>

int n, m, t, arr[1001][1001];

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y]) {
        arr[x][y] = 0;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return;
    }
}

int main() {
    int a, b, c, count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d %d %d", &a, &b, &c);
            arr[i][j] = (int) ((a + b + c) / (double) 3);
        }
    }
    scanf("%d", &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = t <= arr[i][j] ? 255 : 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    printf("%d", count);
}
