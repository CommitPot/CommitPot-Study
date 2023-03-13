#include <stdio.h>

typedef struct element {
    int idx, cnt;
} element;
int n, m, vis[200002] = {0}, f = -1, r = -1;
element queue[200002];

int bfs(int s) {
    queue[++r].idx = s;
    queue[r].cnt = 0;
    while (f != r) {
        int search = queue[++f].idx;
        int cnt = queue[f].cnt;
        if (search == m) return cnt;
        if (!vis[search]) {
            vis[search] = 1;
            if (!vis[search * 2] && search * 2 < 100001) {
                queue[++r].idx = search * 2;
                queue[r].cnt = cnt + 1;
            }
            if (!vis[search + 1] && search + 1 < 100001) {
                queue[++r].idx = search + 1;
                queue[r].cnt = cnt + 1;
            }
            if (!vis[search - 1] && search - 1 >= 0) {
                queue[++r].idx = search - 1;
                queue[r].cnt = cnt + 1;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    printf("%d", bfs(n));
    return 0;
}