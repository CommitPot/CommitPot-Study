#include <stdio.h>

typedef struct element {
    int x, y, s;
} element;

int main() {
    element queue[10000];
    int n, arr[4][4], f = 0, r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    queue[r].x = queue[r].y = 1;
    queue[r].s = arr[1][1];
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int s = queue[f].s;
        if (s == -1) {
            printf("HaruHaru");
            return 0;
        }
        if (!s) continue;
        if (x > 0 && x + s <= n && y > 0 && y <= n) {
            queue[++r].x = x + s;
            queue[r].y = y;
            queue[r].s = arr[x + s][y];
        }
        if (x > 0 && x <= n && y > 0 && y + s <= n) {
            queue[++r].x = x;
            queue[r].y = y + s;
            queue[r].s = arr[x][y + s];
        }
    }
    printf("Hing");
    return 0;
}