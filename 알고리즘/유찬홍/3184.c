#include <stdio.h>

int r, c, wo = 0, sh = 0, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char arr[251][251];

void dfs(int x, int y) {
    if (!x || !y || x > r || y > c || arr[x][y] == '#') return;
    if (arr[x][y] == 'o') {
        sh++;
    } else if (arr[x][y] == 'v') {
        wo++;
    }
    arr[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        dfs(x1, y1);
    }
}

int main() {
    int wol = 0, she = 0;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] != '#') dfs(i, j);
            if (wo < sh) {
                she += sh;
            } else {
                wol += wo;
            }
            wo = sh = 0;
        }
    }
    printf("%d %d", she, wol);
}
