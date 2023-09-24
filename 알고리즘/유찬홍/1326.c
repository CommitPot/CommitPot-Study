#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int x, c;
} e;

int main() {
    int n, a, b, f = 0, r = 0, arr[10001], vis[10001] = {0};
    e queue[10001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &a, &b);
    queue[++r].x = a;
    queue[r].c = 0;
    vis[a] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int c = queue[f].c;
        if (x == b) {
            printf("%d", c);
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (abs(i - x) % arr[x] == 0 && !vis[i]) {
                vis[i] = 1;
                queue[++r].x = i;
                queue[r].c = c + 1;
            }
        }
    }
    printf("-1");
}
