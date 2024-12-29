#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;
element queue[1000000];

int main() {
    int n, m, s = 0, r = 0, arr[1001][1001], max = 0, tco = 0, wco = 0;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                queue[++r].x = i;
                queue[r].y = j;
                queue[r].c = 0;
                tco++;
            } else if (arr[i][j] == -1)wco++;
        }
    }
    if (n * m - (tco + wco) == 0) {
        printf("0");
        return 0;
    }
    while (s < r) {
        int x = queue[++s].x;
        int y = queue[s].y;
        int c = queue[s].c;
        if (arr[x][y] > 0) {
            if (!arr[x + 1][y] && x + 1 <= n) {
                arr[x + 1][y] = c + 1;
                queue[++r].x = x + 1;
                queue[r].y = y;
                queue[r].c = c + 1;
            }
            if (!arr[x - 1][y] && x - 1 > 0) {
                arr[x - 1][y] = c + 1;
                queue[++r].x = x - 1;
                queue[r].y = y;
                queue[r].c = c + 1;
            }
            if (arr[x][y + 1] == 0 && y + 1 <= m) {
                arr[x][y + 1] = c + 1;
                queue[++r].x = x;
                queue[r].y = y + 1;
                queue[r].c = c + 1;
            }
            if (arr[x][y - 1] == 0 && y - 1 > 0) {
                arr[x][y - 1] = c + 1;
                queue[++r].x = x;
                queue[r].y = y - 1;
                queue[r].c = c + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!arr[i][j]) {
                printf("-1");
                return 0;
            }
            if (max < arr[i][j]) max = arr[i][j];
        }
    }
    printf("%d", max);
    return 0;
}