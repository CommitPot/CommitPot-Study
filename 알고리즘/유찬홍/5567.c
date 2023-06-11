#include <stdio.h>

int n, m, c = 0, arr[501][501], vis[501] = {0};

void dfs(int x) {
    vis[x] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[x][i] && !vis[i] && arr[1][x]) {
            c++;
            dfs(i);
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    arr[1][1] = 1;
    dfs(1);
    printf("%d", c);
}
