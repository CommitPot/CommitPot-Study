#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int linkedIdx;
    struct List *link;

} List;
List *arr[32001];


void insert(int listIdx, int linkedIdx) {
    List *node = (List *) malloc(sizeof(List));
    node->linkedIdx = linkedIdx;
    node->link = arr[listIdx];
    arr[listIdx] = node;
}


int main() {
    int n, m, a, b, f = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        arr[i] = NULL;
    }
    int ind[32001] = {0}, queue[32001] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insert(a, b);
        ind[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) queue[++r] = i;
    }
    while (f < r) {
        int x = queue[++f];
        List *list = arr[x];
        while (list != NULL) {
            ind[list->linkedIdx]--;
            if (!ind[list->linkedIdx]) queue[++r] = list->linkedIdx;
            list = list->link;
        }
    }
    for (int i = 1; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    for (int i = 0; i <= n; i++) {
        free(arr[i]);
    }
}
