#include <stdio.h>

int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

typedef struct element {
    int x, y, c;
} element;
element queue[4000000];

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int f = 0, r = 0, n, x1, y1, x2, y2, min = 1000000000;
        int arr[301][301] = {0};
        scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
        queue[++r].x = x1;
        queue[r].y = y1;
        queue[r].c = 0;
        while (f < r) {
            int x = queue[++f].x;
            int y = queue[f].y;
            int c = queue[f].c;
            if (x == x2 && y == y2) {
                if (min > c) min = c;
            }
            if (!arr[x][y]) {
                arr[x][y] = 1;
                for (int j = 0; j < 8; j++) {
                    int a = x + dx[j];
                    int b = y + dy[j];
                    if (a >= 0 && a < n && b >= 0 && b < n) {
                        queue[++r].x = a;
                        queue[r].y = b;
                        queue[r].c = c + 1;
                    }
                }
            }
        }
        printf("%d\n", min);
    }
}