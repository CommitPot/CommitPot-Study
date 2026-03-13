#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, m, r = 1e9;
    char a[10][11], b[10][11] = {};
    scanf("%d %d", &n, &m);
    n--, m--;
    for (int i = 0; i < 10; i++) scanf("%s", a[i]), strcpy(b[i], a[i]);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] == 'o') {
                for (int k = 0; k < 10; k++) b[i][k] = b[k][j] = 'o';
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (b[i][j] == 'x') {
                r = min(r, abs(i - n) + abs(j - m));
            }
        }
    }
    printf("%d", r);
}
