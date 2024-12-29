#include <stdio.h>

int n, m, k, count = 0, arr[101][101] = {0};

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr[x][y]) {
        count++;
        arr[x][y] = 0;
        dfs(x, y - 1);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x + 1, y);
        return;
    }
}

int main() {
    int a, b, sum = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]){
                dfs(i, j);
                if (sum < count) sum = count;
                count = 0;
            }
        }
    }
    printf("%d", sum);
    return 0;
}