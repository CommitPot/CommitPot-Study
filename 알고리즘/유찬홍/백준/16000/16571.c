#include <stdio.h>

int a[3][3];

int f(int t) {
    int r = 2, g = 0, k = 0;
    for (int i = 0; i < 3; i++) {
        int z[2] = {};
        for (int j = 0; j < 2; j++) {
            z[0] += a[i][j] && a[i][j] == a[i][j + 1];
            z[1] += a[j][i] && a[j][i] == a[j + 1][i];
        }
        if (z[0] > 1 || z[1] > 1) g++;
        if (z[0] > 1 && a[i][0] == t) k++;
        if (z[1] > 1 && a[0][i] == t) k++;
    }
    if (a[0][0] && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
        g++;
        if (a[0][0] == t) k++;
    }
    if (a[0][2] && a[0][2] == a[1][1] && a[1][1] == a[2][0]) {
        g++;
        if (a[0][2] == t) k++;
    }
    if (g) return k ? 1 : -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j]) continue;
            a[i][j] = t;
            int x = f((t & 1) + 1);
            r = r < x ? r : x;
            a[i][j] = 0;
        }
    }
    return r == 2 ? 0 : -r;
}

int main() {
    int x = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            x += a[i][j] ? a[i][j] == 1 ? 1 : -1 : 0;
        }
    }
    x = f(x > 0 ? 2 : 1);
    printf("%c", x ? x == 1 ? 'W' : 'L' : 'D');
}

