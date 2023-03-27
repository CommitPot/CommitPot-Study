#include <stdio.h>

typedef struct element {
    int r, c, co;
} element;
int r, c, arr[5][5], vis[5][5] = {0}, s = 0, e = 0;
element queue[101];

int bfs(int x, int y) {
    queue[++e].r = x;
    queue[e].c = y;
    queue[e].co = 0;
    while (s < e) {
        int a = queue[++s].r;
        int b = queue[s].c;
        int co = queue[s].co;
        if (arr[a][b] == 1) return co;
        if (!vis[a][b]) {
            vis[a][b] = 1;
            if (!vis[a - 1][b] && a - 1 >= 0) {
                queue[++e].r = a - 1;
                queue[e].c = b;
                queue[e].co = co + 1;
            }
            if (!vis[a + 1][b] && a + 1 < 5) {
                queue[++e].r = a + 1;
                queue[e].c = b;
                queue[e].co = co + 1;
            }
            if (!vis[a][b - 1] && b - 1 >= 0) {
                queue[++e].r = a;
                queue[e].c = b - 1;
                queue[e].co = co + 1;
            }
            if (!vis[a][b + 1] && b + 1 < 5) {
                queue[++e].r = a;
                queue[e].c = b + 1;
                queue[e].co = co + 1;
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == -1) vis[i][j] = 1;
        }
    }
    scanf("%d %d", &r, &c);
    printf("%d", bfs(r, c));
    return 0;
}