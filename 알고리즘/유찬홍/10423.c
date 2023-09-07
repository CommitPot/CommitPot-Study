#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int u, v, w;
} element;

element arr1[100001];
int n, m, k, arr[1001];

int comp(const void *a, const void *b) {
    return (((element *) a)->w - ((element *) b)->w);
}

int Find(int v) {
    if (arr[v] == v) return v;
    return arr[v] = Find(arr[v]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    arr[x > y ? x : y] = x > y ? y : x;
}

int Same(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x == y;
}

int main() {
    int rs = 0, a, b;
    scanf("%d %d %d %d", &n, &m, &k, &a);
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 1; i < k; i++) {
        scanf("%d", &b);
        arr[b] = a;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arr1[i].u, &arr1[i].v, &arr1[i].w);
    }
    qsort(arr1, m, sizeof(arr1[0]), comp);
    for (int i = 0; i < m; i++) {
        if (!Same(arr1[i].u, arr1[i].v)) {
            rs += arr1[i].w;
            Union(arr1[i].u, arr1[i].v);
        }
    }
    printf("%d", rs);
}
