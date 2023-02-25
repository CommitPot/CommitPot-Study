#include <stdio.h>

int arr[101][101] = {0}, n, m, vis[101][101] = {0};

int px[] = {0, 0, -1, 1};
int py[] = {1, -1, 0, 0};

typedef struct Queue {
    int x;
    int y;
} Queue;

Queue queue[10001];

int bfs(int x, int y) {
    int f = -1, r = -1;
    queue[++r].x = x;
    queue[r].y = y;
    vis[x][y] = 1;
    while (f < r) {
        int dx = queue[++f].x;
        int dy = queue[f].y;
        for (int i = 0; i < 4; i++) {
            int fx = dx + px[i];
            int fy = dy + py[i];
            if (fx > 0 && fx <= n && fy > 0 && fy <= m) {
                if (!vis[fx][fy] && arr[fx][fy]) {
                    queue[++r].x = fx;
                    queue[r].y = fy;
                    vis[fx][fy] = 1;
                    arr[fx][fy] = arr[dx][dy] + 1;
                }
            }
        }
    }
    return arr[n][m];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    printf("%d", bfs(1, 1));
    return 0;
}