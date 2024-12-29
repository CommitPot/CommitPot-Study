#include <stdio.h>

typedef struct element {
    int w, c;
} element;
element queue[100000];
int n, a, b, m, x, y, f = 0, r = 0, arr[101][101] = {0};

int bfs() {
    queue[++r].w = a;
    queue[r].c = 0;
    while (f < r) {
        int w = queue[++f].w;
        int c = queue[f].c;
        if (w == b) { return c; }
        for (int i = 1; i <= n; i++) {
            if (arr[w][i]) {
                queue[++r].w = i;
                queue[r].c = c + 1;
                arr[w][i] = 0;
            }
        }
    }
    return -1;
}


int main() {
    scanf("%d %d %d %d", &n, &a, &b, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    printf("%d", bfs());
    return 0;
}