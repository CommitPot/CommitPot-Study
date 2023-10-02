#include <stdio.h>

typedef struct element {
    int x, cnt;
} element;

int main() {
    element queue[100000];
    int n, k, r = 0, f = 0, vis[100001] = {0}, rs[100001], len;
    scanf("%d %d", &n, &k);
    queue[++r].x = n;
    queue[r].cnt = 0;
    vis[n] = n;
    while (f < r) {
        int x = queue[++f].x;
        int cnt = queue[f].cnt;
        if (x == k) {
            printf("%d\n%d ", cnt, n);
            len = cnt;
            while (x != vis[x]) {
                rs[len--] = x;
                x = vis[x];
            }
            for (int i = 1; i < cnt + 1; i++) {
                printf("%d ", rs[i]);
            }
            break;
        }
        if (x + 1 <= 100000 && !vis[x + 1]) {
            vis[x + 1] = x;
            queue[++r].x = x + 1;
            queue[r].cnt = cnt + 1;
        }
        if (x - 1 >= 0 && !vis[x - 1]) {
            vis[x - 1] = x;
            queue[++r].x = x - 1;
            queue[r].cnt = cnt + 1;
        }
        if (x <= 50000 && !vis[x * 2]) {
            vis[x * 2] = x;
            queue[++r].x = x * 2;
            queue[r].cnt = cnt + 1;
        }
    }
}
