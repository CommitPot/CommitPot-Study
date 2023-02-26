#include <stdio.h>

int n, m, count = 0, sum, sum1;
char arr[102][102];

void dfs(int x, int y, char a) {
    if (!x || !y || x > m || y > n) return;
    if (arr[x][y] == a) {
        count++;
        arr[x][y] = 'A';
        dfs(x, y - 1, a);
        dfs(x, y + 1, a);
        dfs(x - 1, y, a);
        dfs(x + 1, y, a);
        return;
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 'A'){
                char a = arr[i][j];
                dfs(i, j, arr[i][j]);
                if (a == 'W') sum += count * count;
                else sum1 += count * count;
                count = 0;
            }
        }
    }
    printf("%d %d", sum, sum1);
    return 0;
}