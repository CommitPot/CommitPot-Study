#include <stdio.h>

int n, m, d[] = {0, 1, 0, -1, 0};
char arr[2002][2002];

void dfs(int x, int y, int a, int b) {
    if (x == a && y == b) {
        for (int i = 0; i < n; i++) {
            printf("%s\n", arr[i]);
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int dx = x + d[i];
        int dy = y + d[i + 1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && arr[dx][dy] == '@') {
            arr[dx][dy] = '.';
            dfs(dx, dy, a, b);
            arr[dx][dy] = '@';
        }
    }
}

int main() {
    int s[4], c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == '.') arr[i][j] = '@';
            if ((!i || i == n - 1 || !j || j == m - 1) && arr[i][j] == '@') {
                s[c++] = i;
                s[c++] = j;
            }
        }
    }
    arr[s[0]][s[1]] = '.';
    dfs(s[0], s[1], s[2], s[3]);
}
