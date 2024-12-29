#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

element queue[250000];
int arr1[1001][1001];

int main() {
    int n, m, x1, y1, arr[1001][1001], vis[1001][1001] = {0};
    int r = 0, f = 0, dx[] = {-1, 1, 0, 0},
            dy[] = {0, 0, -1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2) {
                x1 = i, y1 = j;
            }
            if (arr[i][j] != 0) arr1[i][j] = -1;
        }
    }
    queue[++r].x = x1;
    queue[r].y = y1;
    queue[r].c = 0;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].c;
        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if (x2 > 0 && x2 <= n && y2 > 0 && y2 <= m) {
                if (!vis[x2][y2] && arr[x2][y2] == 1) {
                    queue[++r].x = x2;
                    queue[r].y = y2;
                    queue[r].c = c + 1;
                    vis[x2][y2] = 1;
                    arr1[x2][y2] = c + 1;
                }
            }
        }
    }
    arr1[x1][y1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
}
