#include <stdio.h>

typedef struct element {
    int x, y, cnt;
} element;

element queue[10000000];

int main() {
    int r, c, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    scanf("%d %d", &c, &r);
    char arr[1001][1001];
    int fr = 0, re = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'J') {
                queue[++re].x = i;
                queue[re].y = j;
                queue[re].cnt = 0;
            }
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (arr[i][j] == 'F') {
                queue[++re].x = i;
                queue[re].y = j;
                queue[re].cnt = -1;
            }
        }
    }
    while (fr < re) {
        int x = queue[++fr].x;
        int y = queue[fr].y;
        int cnt = queue[fr].cnt;
        if ((!x || !y || x + 1 == c || y + 1 == r) && arr[x][y] == 'J') {
            printf("%d", cnt + 1);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if (arr[x][y] == 'J' && arr[nx][ny] == '.') {
                arr[nx][ny] = 'J';
                queue[++re].x = nx;
                queue[re].y = ny;
                queue[re].cnt = cnt + 1;
            } else if (arr[x][y] == 'F' && arr[nx][ny] != '#' && arr[nx][ny] != 'F') {
                arr[nx][ny] = 'F';
                queue[++re].x = nx;
                queue[re].y = ny;
                queue[re].cnt = cnt;
            }
        }
    }
    printf("IMPOSSIBLE");
}
