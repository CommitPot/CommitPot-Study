#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

element queue[100000];

int main() {
    int n, m, f = 50000, r = 50000, vis[101][101] = {0}, arr[101][101], dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    queue[++r].x = 0;
    queue[r].y = 0;
    queue[r].c = 0;
    vis[0][0] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].c;
        if (x == n - 1 && y == m - 1) {
            printf("%d", c);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m) {
                if (!vis[x1][y1]) {
                    vis[x1][y1] = 1;
                    if (!arr[x1][y1]) {
                        queue[f].x = x1;
                        queue[f].y = y1;
                        queue[f--].c = c;
                    } else {
                        queue[++r].x = x1;
                        queue[r].y = y1;
                        queue[r].c = c + 1;
                    }
                }
            }
        }
    }
}
