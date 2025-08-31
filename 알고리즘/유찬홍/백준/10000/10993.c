#include <math.h>
#include <stdio.h>

char r[1024][2048];

void f(int x, int v, int w, int h, int s, int e) {
    if (!v) return;
    for (int i = e; i < e + w; i++) r[v & 1 ? s + h - 1 : s][i] = 42;
    for (int i = 0; i < h; i++) {
        int p = v & 1 ? s + i : s + h - i - 1;
        r[p][x - i] = r[p][x + i] = 42;
    }
    f(x, v - 1, w - (h + 1), h / 2, v & 1 ? s + h / 2 : s + 1, e + (w - h + 2) / 2);
}

int main() {
    int n;
    scanf("%d", &n);
    int x = pow(2, n) - 1;
    f((x * 2 - 1) / 2, n, x * 2 - 1, x, 0, 0);
    for (int i = 0; i < x; i++) {
        int m = n & 1 ? x + i : x * 2 - 1 - i;
        for (int j = 0; j < m; j++) {
            r[i][j] = r[i][j] == 42 ? 42 : 32;
        }
        r[i][m] = 0;
        printf("%s\n", r[i]);
    }
}
