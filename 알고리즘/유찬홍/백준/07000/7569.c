#include <stdio.h>

typedef struct element {
    int x, y, z, c;
} element;
element queue[1000001];

int main() {
    int n, m, h, s = 0, r = 0, arr[101][101][101], max = 0, tco = 0, wco = 0;
    scanf("%d %d %d", &m, &n, &h);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (arr[i][j][k] == 1) {
                    queue[++r].x = i;
                    queue[r].y = j;
                    queue[r].z = k;
                    queue[r].c = 0;
                    tco++;
                } else if (arr[i][j][k] == -1)wco++;
            }
        }
    }
    if (n * m * h - (tco + wco) == 0) {
        printf("0");
        return 0;
    }
    while (s < r) {
        int x = queue[++s].x;
        int y = queue[s].y;
        int z = queue[s].z;
        int c = queue[s].c;
        if (arr[x][y][z] > 0) {
            if (x + 1 <= h) {
                if (!arr[x + 1][y][z]) {
                    arr[x + 1][y][z] = c + 1;
                    queue[++r].x = x + 1;
                    queue[r].y = y;
                    queue[r].z = z;
                    queue[r].c = c + 1;
                }
            }
            if (x - 1 > 0) {
                if (!arr[x - 1][y][z]) {
                    arr[x - 1][y][z] = c + 1;
                    queue[++r].x = x - 1;
                    queue[r].y = y;
                    queue[r].z = z;
                    queue[r].c = c + 1;
                }
            }
            if (y + 1 <= n) {
                if (!arr[x][y + 1][z]) {
                    arr[x][y + 1][z] = c + 1;
                    queue[++r].x = x;
                    queue[r].y = y + 1;
                    queue[r].z = z;
                    queue[r].c = c + 1;
                }
            }
            if (y - 1 > 0) {
                if (!arr[x][y - 1][z]) {
                    arr[x][y - 1][z] = c + 1;
                    queue[++r].x = x;
                    queue[r].y = y - 1;
                    queue[r].z = z;
                    queue[r].c = c + 1;
                }
            }
            if (z + 1 <= m) {
                if (!arr[x][y][z + 1]) {
                    arr[x][y][z + 1] = c + 1;
                    queue[++r].x = x;
                    queue[r].y = y;
                    queue[r].z = z + 1;
                    queue[r].c = c + 1;
                }
            }
            if (z - 1 > 0) {
                if (!arr[x][y][z - 1]) {
                    arr[x][y][z - 1] = c + 1;
                    queue[++r].x = x;
                    queue[r].y = y;
                    queue[r].z = z - 1;
                    queue[r].c = c + 1;
                }
            }
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (!arr[i][j][k]) {
                    printf("-1");
                    return 0;
                }
                if (max < arr[i][j][k]) max = arr[i][j][k];
            }
        }
    }
    printf("%d", max);
    return 0;
}