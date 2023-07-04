#include <stdio.h>

int n, m;
char arr[101][101];

void dfs(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m) {
        if (arr[x + 1][y] == '#') {
            arr[x + 1][y] = '.';
            dfs(x + 1, y);
        }
        if (arr[x - 1][y] == '#') {
            arr[x - 1][y] = '.';
            dfs(x - 1, y);
        }
        if (arr[x][y + 1] == '#') {
            arr[x][y + 1] = '.';
            dfs(x, y + 1);
        }
        if (arr[x][y - 1] == '#') {
            arr[x][y - 1] = '.';
            dfs(x, y - 1);
        }
    }
}

int main() {
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d", cnt);
}
