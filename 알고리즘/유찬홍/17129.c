#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;
element queue[9000000];
char arr[3002][3002], vis[3002][3002];

int main() {
    int n, m, a, b, f = 0, r = 0, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == '2') {
                a = i;
                b = j;
            }
        }
    }
    queue[++r].x = a;
    queue[r].y = b;
    queue[r].c = 0;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].c;
        if (arr[x][y] > '2') {
            printf("TAK\n%d", c);
            return 0;
        } else {
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (arr[x1][y1] != '1' && x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && vis[x1][y1] != '1') {
                    queue[++r].x = x1;
                    queue[r].y = y1;
                    queue[r].c = c + 1;
                    vis[x1][y1] = '1';
                }
            }
        }
    }

    printf("NIE");
}
