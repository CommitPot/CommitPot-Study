#include <stdio.h>

int n, arr[5001][5001] = {0}, vis[5001] = {0};
long long int max = 0;

void dfs(int x, long long int c) {
    vis[x] = 1;
    if (c > max) max = c;
    for (int i = 1; i <= n; i++) {
        if (arr[x][i] > 0 && !vis[i]) {
            dfs(i, c + arr[x][i]);
        }
    }
}

int main() {
    int a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
        arr[b][a] = c;
    }
    dfs(1, 0);
    printf("%lld", max);
}
