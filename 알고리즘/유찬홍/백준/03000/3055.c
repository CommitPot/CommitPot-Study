#include <stdio.h>

typedef struct element {
    int x, y, cnt;
} element;

int main() {
    element queue[10000];
    int r, c, s = 0, e = 0, a, b, vis[51][51] = {0};
    int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
    char arr[51][51];
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'S') {
                queue[++e].x = i;
                queue[e].y = j;
                queue[e].cnt = 0;
            } else if (arr[i][j] == 'D') {
                a = i;
                b = j;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] == '*') {
                queue[++e].x = i;
                queue[e].y = j;
                queue[e].cnt = 0;
                vis[i][j] = 1;
            }
        }
    }
    while (s < e) {
        int x = queue[++s].x;
        int y = queue[s].y;
        int cnt = queue[s].cnt;
        if (x == a && y == b) {
            printf("%d", cnt);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!nx || !ny || nx > r || ny > c) continue;
            if (vis[nx][ny] == 2) continue;
            if (vis[nx][ny] == 1 || !vis[nx][ny]) {
                if (arr[x][y] == '*' && arr[nx][ny] != 'D' && arr[nx][ny] != 'X') {
                    queue[++e].x = nx;
                    queue[e].y = ny;
                    queue[e].cnt = cnt + 1;
                    vis[nx][ny] = 2;
                    arr[nx][ny] = '*';
                }
            }
            if (!vis[nx][ny]) {
                if (arr[x][y] == 'S' && arr[nx][ny] != 'X' && arr[nx][ny] != '*') {
                    queue[++e].x = nx;
                    queue[e].y = ny;
                    queue[e].cnt = cnt + 1;
                    vis[nx][ny] = 1;
                    arr[nx][ny] = 'S';
                }
            }
        }
    }
    printf("KAKTUS");
}
