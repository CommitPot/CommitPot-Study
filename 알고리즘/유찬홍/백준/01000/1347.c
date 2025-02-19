#include <stdio.h>
#include <string.h>

int m(int a, int b, int c) {
    return a > b ? c ? a : b : c ? b : a;
}

int main() {
    char s[51], r[101][102];
    int x = 50, y = 50, z = 0, a[4] = {50, 50, 50, 50};
    scanf("%*d %s", s);
    memset(r, '#', sizeof(r));
    r[x][y] = '.';
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'F') {
            if (z == 0) r[++x][y] = '.', a[0] = m(a[0], x, 1);
            else if (z == 1) r[x][--y] = '.', a[1] = m(a[1], y, 0);
            else if (z == 2) r[--x][y] = '.', a[2] = m(a[2], x, 0);
            else r[x][++y] = '.', a[3] = m(a[3], y, 1);
        } else {
            z = (z + (s[i] > 80 ? 1 : -1)) % 4;
            if (z < 0) z = 3;
        }
    }
    for (int i = a[2]; i <= a[0]; i++) {
        for (int j = a[1]; j <= a[3]; j++) {
            printf("%c", r[i][j]);
        }
        printf("\n");
    }
}
