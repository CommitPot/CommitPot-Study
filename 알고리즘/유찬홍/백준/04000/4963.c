#include <stdio.h>

int w, h, arr[51][51];

int dfs(int x, int y) {
    if (!x || !y || x > w || y > h) return 0;
    if (arr[x][y]) {
        arr[x][y] = 0;
        dfs(x - 1, y);
        dfs(x - 1, y - 1);
        dfs(x + 1, y);
        dfs(x + 1, y + 1);
        dfs(x, y - 1);
        dfs(x + 1, y - 1);
        dfs(x, y + 1);
        dfs(x - 1, y + 1);
        return 1;
    }
    return 0;
}

int main() {
    while (1) {
        int count = 0;
        scanf("%d %d", &h, &w);
        if (!w && !h) return 0;
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                if (dfs(i, j)) count++;
            }
        }
        printf("%d\n", count);
    }
}