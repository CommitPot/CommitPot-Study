#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int v, p;
} element;

int comp(const void *a, const void *b) {
    return ((element *) a)->v - ((element *) b)->v;
}

int main() {
    int n, m, a, b, f = 0, r = 0, graph[1001][1001] = {0}, ind[1001] = {0};
    element queue[1000001];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        ind[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i]) queue[++r].v = i, queue[r].p = 1;
    while (f < r) {
        int v = queue[++f].v;
        int p = queue[f].p;
        for (int i = 1; i <= n; i++) {
            if (graph[v][i]) {
                ind[i]--;
                if (!ind[i]) queue[++r].v = i, queue[r].p = p + 1;
            }
        }
    }
    qsort(queue, n + 1, sizeof(queue[0]), comp);
    for (int i = 1; i <= n; i++) {
        printf("%d ", queue[i].p);
    }
}
