#include <stdio.h>

int m(int a, int b) { return a < b ? a : b; }

int main() {
    int n;
    for (int k = 1; scanf("%d", &n), n; k++) {
        int a[100001][3];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        }
        a[0][2] += a[0][1], a[1][0] += a[0][1], a[1][1] += m(a[0][2], m(a[0][1], a[1][0])), a[1][2] += m(a[0][2], m(
                a[0][1], a[1][1]));
        for (int i = 2; i < n; i++) {
            a[i][0] += m(a[i - 1][0], a[i - 1][1]);
            a[i][1] += m(m(a[i - 1][2], a[i][0]), m(a[i - 1][0], a[i - 1][1]));
            a[i][2] += m(m(a[i - 1][1], a[i - 1][2]), a[i][1]);
        }
        printf("%d. %d\n", k, a[n - 1][1]);
    }
}
