#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int u;
    struct Graph *link;
} Graph;
Graph *list[300001];

void insert(int i, int u) {
    Graph *Node = (Graph *) malloc(sizeof(Graph));
    Node->u = u;
    Node->link = list[i];
    list[i] = Node;
}

int main() {
    int n, m, k, x, a, b, f = 0, r = 0, queue[300001], vis[300001] = {0};
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    vis[x] = 1;
    queue[++r] = x;
    while (f < r) {
        int dx = queue[++f];
        if (vis[dx] >= k + 1) continue;
        Graph *ptr = list[dx];
        while (ptr != NULL) {
            if (!vis[ptr->u]) {
                queue[++r] = ptr->u;
                vis[ptr->u] = vis[dx] + 1;
            }
            ptr = ptr->link;
        }
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == k + 1) {
            c = 1;
            printf("%d\n", i);
        }
        free(list[i]);
    }
    if (!c) printf("-1");
}
