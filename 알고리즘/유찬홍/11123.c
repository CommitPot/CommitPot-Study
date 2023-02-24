#include <stdio.h>

int w, h, t;
char arr[102][102];

void dfs(int x, int y) {
    if (!x || !y || x > w || y > h) return;
    if (arr[x][y] == '#') {
        arr[x][y] = '.';
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return;
    }
    return;
}


int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int count = 0;
        scanf("%d %d", &w, &h);
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                scanf(" %c", &arr[j][k]);
            }
        }
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                if (arr[j][k] != '.') {
                    count++;
                    dfs(j, k);
                }
            }
        }
        printf("%d\n", count);
    }
}