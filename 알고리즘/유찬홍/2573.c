#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int f = 0, r = 0, n, m, arr1[301][301] = {0};
element queue[100000];

void dfs(int x, int y) {
    if (!x || !y || x > n || y > m) return;
    if (arr1[x][y] != 0) {
        arr1[x][y] = 0;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return;
    }
}

int main() {
    int a = 0, arr[301][301];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr1[i][j] = arr[i][j];
                if (arr[i][j]) queue[++r].x = i, queue[r].y = j;
            }
        }
        int f1 = f;
        while (f < r) {
            int c = 0;
            int x = queue[++f].x;
            int y = queue[f].y;
            if (!arr[x + 1][y]) c++;
            if (!arr[x - 1][y]) c++;
            if (!arr[x][y + 1]) c++;
            if (!arr[x][y - 1]) c++;
            arr[x][y] -= c;
            if (!arr[x][y]) arr[x][y] = -1;
        }
        while (f1 < r) {
            int x = queue[++f1].x;
            int y = queue[f1].y;
            if (arr[x][y] < 0) arr[x][y] = 0;
        }
        int c = 0, d = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr1[i][j]) {
                    d = 1;
                    c++;
                    dfs(i, j);
                }
            }
        }
        if (!d) {
            printf("0");
            break;
        }
        if (c > 1) {
            printf("%d", a);
            break;
        }
        a++;
        f = 0, r = 0;
    }
}
