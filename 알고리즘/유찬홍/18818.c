#include <stdio.h>

typedef struct e {
    int x, y, cnt;
} e;

int val(int x, int y, int n) {
    if (x > 0 && x <= n && y > 0 && y <= n) return 1;
    return 0;
}

int main() {
    int n, f = 0, r = 1, vis[4][102][102] = {0}, d[] = {0, 1, 0, -1, 0};
    e queue[40000];
    char arr[102][102];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    vis[0][1][1] = vis[1][1][1] = vis[2][1][1] = vis[3][1][1] = 1;
    queue[1].x = queue[1].y = queue[1].cnt = 1;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int cnt = queue[f].cnt;
        if (x == n && y == n) {
            printf("%d", cnt - 1);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int dx = x + d[i], dy = y + d[i + 1];
            while (arr[dx][dy] == '.' && val(dx, dy, n) && !vis[i][dx][dy]) {
                queue[++r].x = dx;
                queue[r].y = dy;
                queue[r].cnt = cnt + 1;
                vis[i][dx][dy] = 1;
                dx += d[i], dy += d[i + 1];
            }
        }
    }
}
