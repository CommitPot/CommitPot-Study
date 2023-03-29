#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int x, y, c;
} element;
element queue[1000000], c[40001];

int comp(const void *a, const void *b) {
    return (((element *) a)->c - ((element *) b)->c);
}

int main() {
    int n, k, s = 0, r = 0, arr[201][201], in = 0, m = 0, a = 0, b = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d %d", &m, &a, &b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[in].x = i;
            c[in].y = j;
            c[in++].c = arr[i][j];
        }
    }
    qsort(c, n * n, sizeof(c[0]), comp);
    for (int i = 0; i < in; i++) {
        queue[++r].x = c[i].x;
        queue[r].y = c[i].y;
    }
    queue[1].c = 0;
    while (s < r) {
        int x = queue[++s].x;
        int y = queue[s].y;
        int c = queue[s].c;
        if (c == m) break;
        if (arr[x][y] > 0) {
            if (!arr[x + 1][y] && x + 1 <= n) {
                queue[++r].x = x + 1;
                queue[r].y = y;
                queue[r].c = c + 1;
                arr[x + 1][y] = arr[x][y];
            }
            if (!arr[x - 1][y] && x - 1 > 0) {
                queue[++r].x = x - 1;
                queue[r].y = y;
                queue[r].c = c + 1;
                arr[x - 1][y] = arr[x][y];
            }
            if (arr[x][y + 1] == 0 && y + 1 <= n) {
                queue[++r].x = x;
                queue[r].y = y + 1;
                queue[r].c = c + 1;
                arr[x][y + 1] = arr[x][y];
            }
            if (arr[x][y - 1] == 0 && y - 1 > 0) {
                queue[++r].x = x;
                queue[r].y = y - 1;
                queue[r].c = c + 1;
                arr[x][y - 1] = arr[x][y];
            }
        }
    }
    printf("%d", arr[a][b]);
    return 0;
}