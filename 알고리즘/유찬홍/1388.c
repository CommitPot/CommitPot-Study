#include <stdio.h>

int n, m;
char arr[52][52];

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y] == '-') {
        arr[x][y] = 'z';
        dfs(x, y + 1);
        return;
    }
}

void dfs1(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y] == '|') {
        arr[x][y] = 'z';
        dfs1(x + 1, y);
        return;
    }
}

int main() {
    int count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '-') {
                count++;
                dfs(i, j);
            } else if (arr[i][j] == '|'){
                count++;
                dfs1(i, j);
            }
        }
    }
    printf("%d", count);
    return 0;
}