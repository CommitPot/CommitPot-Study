#include <stdio.h>


typedef struct element {
    int x;
    int cnt;
} element;

int main() {
    int a, b, c, d, n, m, f = 0, r = 0, arr[1001][1001] = {0};
    element queue[100000];
    scanf("%d %d %d %d", &a, &b, &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c, &d);
        arr[c][d] = 1;
        arr[d][c] = 1;
    }
    queue[++r].x = a;
    queue[r].cnt = 0;
    while (f < r) {
        int x = queue[++f].x;
        int cnt = queue[f].cnt;
        if (x == b) {
            printf("%d", cnt);
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (arr[x][i]) {
                queue[++r].x = i;
                queue[r].cnt = cnt + 1;
                arr[x][i] = 0;
            }
        }
    }
    printf("-1");
}
