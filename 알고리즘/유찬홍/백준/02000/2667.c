#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int n, c = 0, count = 0, arr[26][26], arr1[313] = {0}, d = 0;

int dfs(int x, int y) {
    if (!x || !y || x > n || y > n) return 0;
    if (arr[x][y]) {
        arr[x][y] = 0;
        arr1[count]++;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j]) {
                count++;
                dfs(i, j);
            }
        }
    }
    qsort(arr1, count + 1, 4, comp);
    printf("%d\n", count);
    for (int i = 1; i <= count; i++) {
        printf("%d\n", arr1[i]);
    }
}