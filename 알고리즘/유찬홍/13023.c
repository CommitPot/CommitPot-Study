#include <stdio.h>

int n, m, z = 0, vis[2001] = {0}, arr[2001][2001];


void dfs(int x, int c) {
    if (c == 4) {
        z = 1;
        return;
    }
    if (z || vis[x]) return;
    vis[x] = 1;
    int len = 0;
    while (arr[x][len] >= 0) len++;
    for (int i = 0; i < len; i++) {
        if (!vis[arr[x][i]]) {
            dfs(arr[x][i], c + 1);
        }
    }
    vis[x] = 0;
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            arr[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        int len = 0;
        while (arr[a][len] >= 0) len++;
        arr[a][len] = b;
        len = 0;
        while (arr[b][len] >= 0) len++;
        arr[b][len] = a;
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
        if (z) {
            printf("1");
            return 0;
        }
    }
    printf("0");
}
