#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *link;
    int u;
} Node;
Node *arr[20001];
int v, e, vis[20001];

void init(int x) {
    for (int i = 1; i <= x; i++) {
        arr[i] = NULL;
        vis[i] = -1;
    }
}


void insert(int listIdx, int u) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->u = u;
    node->link = arr[listIdx];
    arr[listIdx] = node;
}

void freeList(int x) {
    for (int i = 1; i <= x; i++) {
        free(arr[i]);
    }
}


void dfs(int x, int color) {
    Node *ptr = arr[x];
    while (ptr != NULL) {
        if (vis[ptr->u] == -1) {
            vis[ptr->u] = color;
            dfs(ptr->u, !color);
        }
        ptr = ptr->link;
    }
}

int check(int x) {
    for (int i = 1; i <= x; i++) {
        Node *ptr = arr[i];
        int c = vis[i];
        while (ptr != NULL) {
            if (c == vis[ptr->u]) return 1;
            ptr = ptr->link;
        }
    }
    return 0;
}

int main() {
    int k, a, b;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &v, &e);
        init(v);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            insert(a, b);
            insert(b, a);
        }
        for (int i = 1; i <= v; i++) {
            if (vis[i] == -1) {
                vis[i] = 0;
                dfs(i, 1);
            }
        }
        printf("%s\n", check(v) ? "NO" : "YES");
        freeList(v);
    }
}
