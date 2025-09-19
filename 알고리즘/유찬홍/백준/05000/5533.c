#include <stdio.h>

int main() {
    int n, a[201][3], b[101][3] = {}, c[201] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        b[a[i][0]][0]++;
        b[a[i][1]][1]++;
        b[a[i][2]][2]++;
    }
    for (int i = 0; i < n; i++) {
        if (b[a[i][0]][0] == 1) c[i] += a[i][0];
        if (b[a[i][1]][1] == 1) c[i] += a[i][1];
        if (b[a[i][2]][2] == 1) c[i] += a[i][2];
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", c[i]);
    }
}
