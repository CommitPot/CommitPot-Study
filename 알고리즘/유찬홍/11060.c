#include <stdio.h>

typedef struct element {
    int x, cnt;
} element;

int main() {
    int n, f = 0, r = 0, arr[1001], vis[1001] = {0};
    element queue[10000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    queue[++r].x = 1;
    queue[r].cnt = 0;
    vis[1] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int cnt = queue[f].cnt;
        if (x == n) {
            printf("%d", cnt);
            return 0;
        }
        for (int i = 1; i <= arr[x]; i++) {
            if (!vis[x + i]) {
                vis[x + i] = 1;
                queue[++r].x = x + i;
                queue[r].cnt = cnt + 1;
            }
        }
    }
    printf("-1");
}
