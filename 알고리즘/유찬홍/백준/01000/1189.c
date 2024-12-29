#include <stdio.h>

int r, c, k, count = 0, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char arr[6][6], vis[6][6];

void dfs(int x, int y, int cnt) {
    if (cnt > k) return;
    if (cnt == k && x == 1 && y == c) {
        count++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (vis[x1][y1] != 'a' && x1 && x1 <= r && y1 && y1 <= c) {
            if (arr[x1][y1] != 'T') {
                vis[x1][y1] = 'a';
                dfs(x1, y1, cnt + 1);
                vis[x1][y1] = 'b';
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    vis[r][1] = 'a';
    dfs(r, 1, 1);
    printf("%d", count);
}
