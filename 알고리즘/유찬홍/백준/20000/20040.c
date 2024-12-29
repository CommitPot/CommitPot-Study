#include <stdio.h>

int n, m, arr[500001];


int find_set(int x) {
    if (arr[x] == x) return x;
    return arr[x] = find_set(arr[x]);
}

void union_set(int x, int y) {
    int x1 = find_set(x);
    int y1 = find_set(y);
    arr[x1 > y1 ? x1 : y1] = x1 > y1 ? y1 : x1;
}

int isSame(int x, int y) {
    int x1 = find_set(x);
    int y1 = find_set(y);
    return x1 == y1;
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        if (isSame(arr[a], arr[b])) {
            printf("%d", i);
            return 0;
        }
        union_set(a, b);
    }
    printf("0");
}
