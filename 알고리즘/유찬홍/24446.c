#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int u;
    struct Graph *graph;
} Graph;

Graph *list[100001];

void init(int n, int *vis) {
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
        vis[i] = -1;
    }
}

void freeList(int n) {
    for (int i = 1; i <= n; i++) {
        free(list[i]);
    }
}

void insert(int i, int u) {
    Graph *node = (Graph *) malloc(sizeof(Graph));
    node->u = u;
    node->graph = list[i];
    list[i] = node;
}

int main() {
    int n, m, s, a, b, f = 0, r = 0, queue[100000], vis[100001];
    scanf("%d %d %d", &n, &m, &s);
    init(n, vis);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    vis[s] = 0;
    queue[++r] = s;
    while (f < r) {
        int v = queue[++f];
        Graph *l = list[v];
        while (l != NULL) {
            if (vis[l->u] == -1) {
                vis[l->u] = vis[v] + 1;
                queue[++r] = l->u;
            }
            l = l->graph;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", vis[i]);
    }
    freeList(n);
}
