#include <stdio.h>

typedef struct E {
    int c, m;
} E;
E queue[50000];
int vis[1001][1001];

int main() {
    int n, f = 0, r = 0;
    scanf("%d", &n);
    queue[++r].m = 1;
    queue[r].c = 0;
    vis[1][0] = 1;
    while (f < r) {
        E e = queue[++f];
        if (e.m == n) {
            printf("%d", vis[e.m][e.c] - 1);
            break;
        }
        E ne;
        ne.m = e.m;
        ne.c = e.m;
        int v = vis[e.m][e.c] + 1;
        if (ne.m <= 1000 && !vis[ne.m][ne.c]) {
            vis[ne.m][ne.c] = v;
            queue[++r] = ne;
        }
        ne.m = e.m + e.c;
        ne.c = e.c;
        if (ne.m <= 1000 && !vis[ne.m][ne.c]) {
            vis[ne.m][ne.c] = v;
            queue[++r] = ne;
        }
        ne.m = e.m - 1;
        ne.c = e.c;
        if (ne.m >= 0 && !vis[ne.m][ne.c]) {
            vis[ne.m][ne.c] = v;
            queue[++r] = ne;
        }
    }
}
