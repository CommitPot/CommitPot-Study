#include <stdio.h>
#include <stdlib.h>

int n, r = 0, vis[10001] = {0};

typedef struct Graph {
    int vtx;
    int linkedIdx;
    struct Graph *link;

} Graph;
Graph *list[10001];

void init() {
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
    }
}


void insert(int listIdx, int linkedIdx, int vtx) {
    Graph *node = (Graph *) malloc(sizeof(Graph));
    node->vtx = vtx;
    node->linkedIdx = linkedIdx;
    node->link = list[listIdx];
    list[listIdx] = node;
}

void freeList() {
    for (int i = 1; i <= n; i++) {
        free(list[i]);
    }
}


void dfs(int x, int sum) {
    if (sum > r) r = sum;
    Graph *ptr = list[x];
    while (ptr != NULL) {
        if (!vis[ptr->linkedIdx] && ptr->vtx > 0) {
            vis[ptr->linkedIdx] = 1;
            dfs(ptr->linkedIdx, sum + ptr->vtx);
            vis[ptr->linkedIdx] = 0;
        }
        ptr = ptr->link;
    }
}

int main() {
    int a, b, c;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        insert(a, b, c);
        insert(b, a, c);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dfs(i, 0);
        vis[i] = 0;
    }
    printf("%d", r);
    freeList();
}
