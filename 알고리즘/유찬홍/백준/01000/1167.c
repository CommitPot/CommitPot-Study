#include <stdio.h>
#include <stdlib.h>

int n, maxLen = 0, maxNode = 0, vis[100001] = {0};

typedef struct Graph {
    int vtx;
    int linkedIdx;
    struct Graph *link;

} Graph;
Graph *list[100001];

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
    if (maxLen < sum) {
        maxLen = sum;
        maxNode = x;
    }
    Graph *ptr = list[x];

    vis[x] = 1;
    while (ptr != NULL) {
        if (!vis[ptr->linkedIdx] && ptr->vtx > 0) {
            vis[ptr->linkedIdx] = 1;
            dfs(ptr->linkedIdx, sum + ptr->vtx);
        }
        ptr = ptr->link;
    }
}

int main() {
    int a, b, c;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        while (1) {
            scanf("%d", &b);
            if (b == -1) break;
            scanf("%d", &c);
            insert(a, b, c);
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    dfs(maxNode, 0);
    printf("%d", maxLen);
    freeList();
}
