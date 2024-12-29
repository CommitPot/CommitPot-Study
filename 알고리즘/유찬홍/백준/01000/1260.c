#include <stdio.h>

int arr[1001][1001] = {0}, queue[1001], dfsVis[1001] = {0}, bfsVis[1001] = {0};

void dfs(int v, int n) {
    dfsVis[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) {
        if (arr[v][i] && !dfsVis[i]) dfs(i, n);
    }
}

void bfs(int v, int n) {
    int f = 0, r = 0;
    printf("%d ", v);
    queue[r++] = v;
    bfsVis[v] = 1;
    while (f < r) {
        int p = queue[f++];
        for (int i = 1; i <= n; i++) {
            if (arr[p][i] == 1 && !bfsVis[i]) {
                printf("%d ", i);
                queue[r++] = i;
                bfsVis[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, v, x, y;
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    dfs(v, n);
    printf("\n");
    bfs(v, n);
    return 0;
}