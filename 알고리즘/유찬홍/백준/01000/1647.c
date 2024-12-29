#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int u, v, w;
} element;
int n, m, arr[100001];
element arr1[1000001];

int comp(const void *a, const void *b) {
    return ((element *) a)->w - ((element *) b)->w;
}

int Find(int x) {
    if (arr[x] == x) return x;
    return arr[x] = Find(arr[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    arr[x > y ? x : y] = x > y ? y : x;
}

int main() {
    int rs = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arr1[i].u, &arr1[i].v, &arr1[i].w);
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    qsort(arr1, m, sizeof(arr1[0]), comp);
    for (int i = 0, len = 0; len < n - 2; i++) {
        if (Find(arr1[i].u) != Find(arr1[i].v)) {
            rs += arr1[i].w;
            Union(arr1[i].u, arr1[i].v);
            len++;
        }
    }
    printf("%d", rs);
}
