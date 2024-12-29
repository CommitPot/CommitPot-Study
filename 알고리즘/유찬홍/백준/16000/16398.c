#include <stdio.h>
#include <stdlib.h>

int arr[1001];

typedef struct element {
    int u1, u2, w;
} element;

element arr1[1000001];

int comp(const void *a, const void *b) {
    return (((element *) a)->w - ((element *) b)->w);
}

int Find(int v) {
    if (arr[v] == v) return v;
    return arr[v] = Find(arr[v]);
}

int Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return 0;
    arr[x > y ? x : y] = x > y ? y : x;
    return 1;
}

int main() {
    int n, a;
    long long int rs = 0;
    scanf("%d", &n);
    for (int i = 1, k = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a);
            if (i != j) {
                arr1[k].u1 = i;
                arr1[k].u2 = j;
                arr1[k++].w = a;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    qsort(arr1, n * n - n, sizeof(arr1[0]), comp);
    for (int i = 0; i < n * n - n; i++) {
        if (Union(arr1[i].u1, arr1[i].u2)) rs += arr1[i].w;
    }
    printf("%lld", rs);
}
