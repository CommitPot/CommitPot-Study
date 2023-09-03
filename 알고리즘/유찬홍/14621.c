#include <stdio.h>
#include <stdlib.h>

int arr[1001];
char s[1001];

typedef struct element {
    int u1, u2, w;
} element;

element arr1[10001];

int comp(const void *a, const void *b) {
    return (((element *) a)->w - ((element *) b)->w);
}

int Find(int v) {
    if (arr[v] == v) return v;
    return arr[v] = Find(arr[v]);
}

void Union(int x, int y) {
    int x1 = Find(x);
    int y1 = Find(y);
    if (x1 > y1) arr[x1] = y1;
    else arr[y1] = x1;
}

int Same(int x, int y) {
    int x1 = Find(x);
    int y1 = Find(y);
    if (x1 == y1) return 1;
    return 0;
}

int main() {
    int n, m, rs = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &s[i]);
        arr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arr1[i].u1, &arr1[i].u2, &arr1[i].w);
    }
    qsort(arr1, m, sizeof(arr1[0]), comp);
    for (int i = 0; i < m; i++) {
        if (!Same(arr1[i].u1, arr1[i].u2) && s[arr1[i].u1] != s[arr1[i].u2]) {
            rs += arr1[i].w;
            Union(arr1[i].u1, arr1[i].u2);
            for (int j = 1; j <= n; j++) {
                Find(j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i + 1]) cnt++;
    }
    printf("%d", cnt ? -1 : rs);
}
