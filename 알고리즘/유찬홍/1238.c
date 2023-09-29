#include <stdio.h>

#define INF 1000000000
int n, m, x, a, b, c, arr[1001][1001], vis[1001], arr1[1001], arr2[1001], r_arr[1001][1001];

int findSmall(int *e) {
    int min = INF;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (e[i] < min && !vis[i]) {
            min = e[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int s, int *e, int isReverse) {
    if (isReverse) {
        for (int i = 1; i <= n; i++) {
            e[i] = r_arr[s][i];
        }
        e[s] = 0;
        vis[s] = 1;
        for (int i = 1; i <= n; i++) {
            int cur = findSmall(e);
            vis[cur] = 1;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && e[cur] + r_arr[cur][j] < e[j]) {
                    e[j] = e[cur] + r_arr[cur][j];
                }
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        e[i] = arr[s][i];
    }
    e[s] = 0;
    vis[s] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = findSmall(e);
        vis[cur] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && e[cur] + arr[cur][j] < e[j]) {
                e[j] = e[cur] + arr[cur][j];
            }
        }
    }
}

int main() {
    int rs = -1;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
            r_arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
        r_arr[b][a] = c;
    }
    dijkstra(x, arr1, 0);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dijkstra(x, arr2, 1);
    for (int i = 1; i <= n; i++) {
        if (rs < arr1[i] + arr2[i]) rs = arr1[i] + arr2[i];
    }
    printf("%d", rs);
}
