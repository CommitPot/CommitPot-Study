#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

element queue[10000000];

int main() {
    int n, w, h, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w, &h);
        char arr[1001][1001];
        int f = 0, r = 0, s = 0;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                scanf(" %1c", &arr[j][k]);
                if (arr[j][k] == '@') {
                    queue[++r].x = j;
                    queue[r].y = k;
                    queue[r].c = 0;
                }
            }
        }
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (arr[j][k] == '*') {
                    queue[++r].x = j;
                    queue[r].y = k;
                    queue[r].c = -1;
                }
            }
        }
        while (f < r) {
            int x = queue[++f].x;
            int y = queue[f].y;
            int c = queue[f].c;
            if ((!x || !y || x + 1 == h || y + 1 == w) && arr[x][y] == '@') {
                printf("%d\n", c + 1);
                s++;
                break;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (arr[x][y] == '@' && arr[nx][ny] == '.') {
                    arr[nx][ny] = '@';
                    queue[++r].x = nx;
                    queue[r].y = ny;
                    queue[r].c = c + 1;
                } else if (arr[x][y] == '*' && arr[nx][ny] != '#' && arr[nx][ny] != '*') {
                    arr[nx][ny] = '*';
                    queue[++r].x = nx;
                    queue[r].y = ny;
                    queue[r].c = c;
                }
            }
        }
        if (!s) printf("IMPOSSIBLE\n");
    }
}
