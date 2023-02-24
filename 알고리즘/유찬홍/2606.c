#include <stdio.h>

int n, c = 0, arr[101][101] = {0}, v[101] = {0};

void dfs(int x, int y) {
    if (!x || !y || x > n, y > n) return;
    if (arr[x][y]) {
        v[x] = 1;
        for (int i = 2; i <= n; i++) {
            if (arr[x][i] && !v[i]){
                c++;
                dfs(i, x);
            }
        }
        return;
    }
    return;
}

int main() {
    int m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    arr[1][1] = 1;
    dfs(1, 1);
    printf("%d", c);
}