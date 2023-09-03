#include <stdio.h>

int n, m, arr[100001] = {0};

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
    int a, b, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    scanf("%d", &a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        if (Find(arr[a]) != Find(arr[b])) cnt++;
        a = b;
    }
    printf("%d", cnt);
}
