#include <stdio.h>

int t, n, a;
int arr[1001][1001] = {0};
int vis[1001] = {0};

void dfs(int x) {
    vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[x][i] && !vis[i]) {
            arr[x][i] = 0;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int count = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a);
            arr[j][a] = 1;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] == 1) {
                    dfs(k);
                    count++;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = 0;
            }
        }
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
        }
        printf("%d\n", count);
    }
}
