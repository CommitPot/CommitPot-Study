#include <stdio.h>

int n, m, c = 0;
char arr[602][602];

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y] == 'P') c++;
    if (arr[x][y] != 'X') {
        arr[x][y] = 'X';
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return;
    }
}

int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 'I') dfs(i, j);
        }
    }
    if (!c) printf("TT");
    else printf("%d", c);
    return 0;
}