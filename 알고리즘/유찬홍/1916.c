#include <stdio.h>

#define INF 1000000000

int n, m, s, e, a, b, c, arr[1001][1001], vis[1001] = {0}, arr1[1001] = {0};

int smallIndex() {
    int min = INF;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (arr1[i] < min && !vis[i]) {
            min = arr1[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (arr[a][b] > c) arr[a][b] = c;
    }
    scanf("%d %d", &s, &e);
    for (int i = 1; i <= n; i++) {
        arr1[i] = arr[s][i];
    }
    arr1[s] = 0;
    vis[s] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = smallIndex();
        vis[cur] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && arr1[cur] + arr[cur][j] < arr1[j]) {
                arr1[j] = arr1[cur] + arr[cur][j];
            }
        }
    }
    printf("%d", arr1[e]);
}
