#include <stdio.h>

int n, m, arr[1001][1001] = {0}, v[1001] = {0};

void dfs(int x) {
    v[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[x][i] && !v[i]) {
            dfs(i);
        }
    }
}

int main() {
    int a, b, c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]){
            c++;
            dfs(i);
        }
    }
    printf("%d", c);
}