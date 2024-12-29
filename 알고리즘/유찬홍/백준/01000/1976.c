#include <stdio.h>

int n, m, arr[201] = {0};

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

int main() {
    int a, b, v[201];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &v[j]);
            if (v[j]) Union(arr[i], j);
        }
    }
    scanf("%d", &a);
    for (int i = 1; i < m; i++) {
        scanf("%d", &b);
        if (Find(a) != Find(b)) {
            printf("NO");
            return 0;
        }
        a = b;
    }
    printf("YES");
}
