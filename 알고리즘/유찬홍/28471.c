#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main() {
    int n, f = 0, r = 0, cnt = 0;
    int dx[] = {0, 0, 1, 1, -1, -1, -1},
            dy[] = {1, -1, -1, 1, 0, 1, -1};
    element queue[4000001];
    char arr[2001][2001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'F') {
                queue[++r].x = i;
                queue[r].y = j;
                arr[i][j] = '#';
            }
        }
    }
    while (f < r) {
        int x = queue[++f].x, y = queue[f].y;
        for (int i = 0; i < 7; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == '#') continue;
            queue[++r].x = nx;
            queue[r].y = ny;
            arr[nx][ny] = '#';
            cnt++;
        }
    }
    printf("%d", cnt);
}
