#include <stdio.h>

int n, r1, r2, c1, c2, f = 0, r = 0;

typedef struct element {
    int count, x, y;
} element;
element queue[400000];
int arr[201][201] = {0};

int bfs(int a, int b) {
    queue[++r].x = a;
    queue[r].y = b;
    queue[r].count = 0;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].count;
        if (x == r2 && y == c2) return c;
        if (!arr[x][y]) {
            arr[x][y] = 1;
            if (!arr[x - 2][y - 1] && x - 2 >= 0 && y - 1 >= 0) {
                queue[++r].x = x - 2;
                queue[r].y = y - 1;
                queue[r].count = c + 1;
            }
            if (!arr[x - 2][y + 1] && x - 2 >= 0 && y + 1 <= n) {
                queue[++r].x = x - 2;
                queue[r].y = y + 1;
                queue[r].count = c + 1;
            }
            if (!arr[x][y - 2] && y - 2 >= 0) {
                queue[++r].x = x;
                queue[r].y = y - 2;
                queue[r].count = c + 1;
            }
            if (!arr[x][y + 2] && y + 2 <= n) {
                queue[++r].x = x;
                queue[r].y = y + 2;
                queue[r].count = c + 1;
            }
            if (!arr[x + 2][y - 1] && x + 2 <= n && y - 1 >= 0) {
                queue[++r].x = x + 2;
                queue[r].y = y - 1;
                queue[r].count = c + 1;
            }
            if (!arr[x + 2][y + 1] && x + 2 <= n && y + 1 <= n) {
                queue[++r].x = x + 2;
                queue[r].y = y + 1;
                queue[r].count = c + 1;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    printf("%d", bfs(r1, c1));
    return 0;
}