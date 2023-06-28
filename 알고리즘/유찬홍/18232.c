#include <stdio.h>
#include <stdlib.h>

int n, m, s, e, vis[300001] = {0};

typedef struct {
    int x, cnt;
} element;

element queue[300000];

typedef struct Graph {
    int vtx;
    struct Graph *link;

} Graph;
Graph *list[300001];

void init() {
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
    }
}


void insert(int listIdx, int vtx) {
    Graph *node = (Graph *) malloc(sizeof(Graph));
    node->vtx = vtx;
    node->link = list[listIdx];
    list[listIdx] = node;
}

void freeList() {
    for (int i = 1; i <= n; i++) {
        free(list[i]);
    }
}


int main() {
    int a, b, r = 0, f = 0;
    scanf("%d %d %d %d", &n, &m, &s, &e);
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    queue[++r].x = s;
    queue[r].cnt = 0;
    vis[s] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int cnt = queue[f].cnt;
        if (x == e) {
            printf("%d", cnt);
            break;
        }
        if (list[x] != NULL) {
            Graph *node = list[x];
            vis[x] = 1;
            while (node != NULL) {
                if (!vis[node->vtx]) {
                    vis[node->vtx] = 1;
                    queue[++r].x = node->vtx;
                    queue[r].cnt = cnt + 1;
                }
                node = node->link;
            }
        }
        if (x + 1 <= 300000 && !vis[x + 1]) {
            vis[x + 1] = 1;
            queue[++r].x = x + 1;
            queue[r].cnt = cnt + 1;
        }
        if (x - 1 >= 1 && !vis[x - 1]) {
            vis[x - 1] = 1;
            queue[++r].x = x - 1;
            queue[r].cnt = cnt + 1;
        }
    }
    freeList();
}
