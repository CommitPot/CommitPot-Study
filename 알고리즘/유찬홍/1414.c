#include <stdio.h>
#include <stdlib.h>

int arr[51];

typedef struct element {
    int u1, u2, w;
} element;

element arr1[2501];

int comp(const void *a, const void *b) {
    return (((element *) a)->w - ((element *) b)->w);
}

int f(int v) {
    if (arr[v] == v) return v;
    return arr[v] = f(arr[v]);
}

int u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return 0;
    arr[x > y ? x : y] = x > y ? y : x;
    return 1;
}

int main() {
    char a;
    int n, rs = 0, sum = 0, cnt = 0, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &a);
            if (a == 48) continue;
            sum += a >= 97 ? a - 96 : a - 38;
            if (i == j) continue;
            arr1[cnt].u1 = i;
            arr1[cnt].u2 = j;
            arr1[cnt++].w = a >= 97 ? a - 96 : a - 38;
        }
    }
    for (int i = 1; i <= n; i++) arr[i] = i;
    qsort(arr1, cnt, sizeof(arr1[0]), comp);
    for (int i = 0; i < cnt; i++) {
        if (u(arr1[i].u1, arr1[i].u2)) {
            rs += arr1[i].w;
            s++;
        }
    }
    printf("%d", s != n - 1 ? -1 : sum - rs);
}
