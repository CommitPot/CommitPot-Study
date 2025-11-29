#include <stdio.h>

int main() {
    int n, l, p[1001][3] = {}, r = 0;
    scanf("%d %d", &n, &l);
    for (int i = 1, a, b, c; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        p[a][0] = i;
        p[a][1] = b;
        p[a][2] = c;
    }
    for (int i = 1; i <= l; i++) {
        if (!p[i][0]) continue;
        if ((i + r) % (p[i][1] + p[i][2]) + 1 <= p[i][1]) r += p[i][1] - (i + r) % (p[i][1] + p[i][2]);
    }
    printf("%d", r + l);
}
