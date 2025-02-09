#include <stdio.h>

int main() {
    int n, r, a[7][2];
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    while (a[2][0] != a[4][0]) {
        a[6][0] = a[0][0];
        a[6][1] = a[0][1];
        for (int i = 1; i < 6; i++) {
            a[i - 1][0] = a[i][0];
            a[i - 1][1] = a[i][1];
        }
        a[5][0] = a[6][0];
        a[5][1] = a[6][1];
    }
    if (a[0][1] > a[2][1]) r = a[2][1] * a[1][1];
    else r = a[1][1] * a[0][1];
    r += a[4][1] * a[5][1];
    printf("%d", r * n);
}
