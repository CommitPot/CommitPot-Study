#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int u;
    struct Graph *graph;
} Graph;

Graph *list[100001];
int sum = 0;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
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

void dfs(int v, int k, int *vis, int *arr) {
    Graph *l = list[v];
    if (arr[v]) sum++;
    while (l != NULL) {
        if (!vis[l->u]) {
            if (vis[v] == k) return;
            vis[l->u] = vis[v] + 1;
            dfs(l->u, k, vis, arr);
        }
        l = l->graph;
    }
}

int main() {
    int n, k, a, b, vis[100001], arr[100001];
    scanf("%d %d", &n, &k);
    init(n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    vis[0] = 0;
    dfs(0, k, vis, arr);
    printf("%d", sum);
    freeList(n);
}
