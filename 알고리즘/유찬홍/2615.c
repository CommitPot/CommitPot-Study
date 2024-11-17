#include <stdio.h>

int f(int a[27][27], int x, int y, int z) {
    if (!a[x][y]) return 0;
    if (a[x][y - 1] != z && a[x][y + 1] == z && a[x][y + 2] == z && a[x][y + 3] == z && a[x][y + 4] == z &&
        a[x][y + 5] != z)
        return 1;
    if (a[x - 1][y] != z && a[x + 1][y] == z && a[x + 2][y] == z && a[x + 3][y] == z && a[x + 4][y] == z &&
        a[x + 5][y] != z)
        return 1;
    if (a[x - 1][y - 1] != z && a[x + 1][y + 1] == z && a[x + 2][y + 2] == z && a[x + 3][y + 3] == z &&
        a[x + 4][y + 4] == z && a[x + 5][y + 5] != z)
        return 1;
    if (a[x + 1][y - 1] != z && a[x - 1][y + 1] == z && a[x - 2][y + 2] == z && a[x - 3][y + 3] == z &&
        a[x - 4][y + 4] == z && a[x - 5][y + 5] != z)
        return 1;
    return 0;
}

int main() {
    int a[27][27] = {};
    for (int i = 4; i < 23; i++) {
        for (int j = 4; j < 23; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 4; i < 23; i++) {
        for (int j = 4; j < 23; j++) {
            if (f(a, i, j, a[i][j])) {
                printf("%d\n%d %d", a[i][j], i - 3, j - 3);
                return 0;
            }
        }
    }
    printf("0");
}
