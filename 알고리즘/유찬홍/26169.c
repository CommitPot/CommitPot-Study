#include <stdio.h>

int r, c, rs, arr[5][5], dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt, int mov) {
    if (mov > 3) return;
    else {
        if (cnt == 2) {
            rs = 1;
            return;
        } else
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 >= 0 && x1 < 5 && y1 >= 0 && y1 < 5) {
                    if (arr[x1][y1] == 1) {
                        arr[x1][y1] = -1;
                        dfs(x1, y1, cnt + 1, mov + 1);
                        arr[x1][y1] = 1;
                    } else if (arr[x1][y1] == 0) {
                        arr[x1][y1] = -1;
                        dfs(x1, y1, cnt, mov + 1);
                        arr[x1][y1] = 0;
                    }
                }
            }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d", &r, &c);
    arr[r][c] = -1;
    dfs(r, c, 0, 0);
    printf("%d", rs);
}
