#include <stdio.h>

int n;
char arr[102][102], arr1[102][102];

void dfs(int x, int y, char a) {
    if (!x || !y || x > n || y > n) return;
    if (arr[x][y] == a) {
        arr[x][y] = 65;
        dfs(x - 1, y, a);
        dfs(x + 1, y, a);
        dfs(x, y + 1, a);
        dfs(x, y - 1, a);
        return;
    }
    return;
}

void dfs1(int x, int y, char a) {
    if (!x || !y || x > n || y > n) return;
    if (arr1[x][y] == a || (arr1[x][y] == 'G' && a == 'R') || (arr1[x][y] == 'R' && a == 'G')) {
        arr1[x][y] = 65;
        dfs1(x - 1, y, a);
        dfs1(x + 1, y, a);
        dfs1(x, y + 1, a);
        dfs1(x, y - 1, a);
        return;
    }
    return;
}

int main() {
    int count = 0, count1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &arr[i][j]);
            arr1[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 65) {
                count++;
                dfs(i, j, arr[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr1[i][j] != 65) {
                count1++;
                dfs1(i, j, arr1[i][j]);
            }
        }
    }
    printf("%d %d", count, count1);
}