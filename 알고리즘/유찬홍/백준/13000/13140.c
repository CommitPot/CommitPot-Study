#include <stdio.h>
#include <stdlib.h>

int v[10];

int c(int *p) {
    return p[0] * 10000 + p[1] * 1000 + p[2] * 100 + p[3] * 10 + p[4];
}

void f(int l, int *a, int n) {
    if (l > 6) {
        int x = c((int[]){a[0], a[1], a[2], a[2], a[3]}), y = c((int []){a[4], a[3], a[5], a[2], a[6]});
        if (x + y == n) {
            printf("  %d\n+ %d\n-------\n %s%d", x, y, n > 1e5 ? "" : " ", n);
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (v[i] || (!i && (!l || l == 4))) continue;
        v[i] = 1, a[l] = i;
        f(l + 1, a, n);
        v[i] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    f(0, (int [7]){}, n);
    printf("No Answer");
}
