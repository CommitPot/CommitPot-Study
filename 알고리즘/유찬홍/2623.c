#include <stdio.h>

int main() {
    int n, m, a, b, c, f = 0, r = 0, graph[1001][1001] = {0}, ind[1001] = {0};
    int queue[1000001];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        for (int j = 1; j < a; j++) {
            scanf("%d", &c);
            if (!graph[b][c]) {
                graph[b][c] = 1;
                ind[c]++;
            }
            b = c;
        }
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) queue[++r] = i;
    while (f < r) {
        int v = queue[++f];
        for (int i = 1; i <= n; i++) {
            if (graph[v][i]) {
                ind[i]--;
                if (!ind[i]) queue[++r] = i;
            }
        }
    }
    if (r != n) {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", queue[i]);
    }
}
