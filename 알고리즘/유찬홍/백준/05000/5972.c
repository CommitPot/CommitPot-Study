#include <stdio.h>
#include <stdlib.h>

int n, m, dist[50001];

typedef struct Graph {
    int v;
    int u;
    struct Graph *link;

} Graph;
Graph *list[50001];


void insert(int i, int u, int v) {
    Graph *node = (Graph *) malloc(sizeof(Graph));
    node->v = v;
    node->u = u;
    node->link = list[i];
    list[i] = node;
}

int main() {
    int a, b, c, queue[50001], f = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
        list[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        insert(a, b, c);
        insert(b, a, c);
    }
    queue[++r] = 1;
    dist[1] = 0;
    while (f != r) {
        f = (f + 1) % 50000;
        int cur = queue[f];
        Graph *ptr1 = list[cur];
        while (ptr1 != NULL) {
            if (dist[ptr1->u] > dist[cur] + ptr1->v) {
                dist[ptr1->u] = dist[cur] + ptr1->v;
                r = (r + 1) % 50000;
                queue[r] = ptr1->u;
            }
            ptr1 = ptr1->link;
        }
    }
    printf("%d", dist[n]);
}
