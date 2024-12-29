#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, s, rs, d[2][2];
    scanf("%d %d", &n, &rs);
    d[0][0] = d[0][1] = rs;
    while (--n) {
        scanf("%d", &s);
        d[1][0] = max(d[0][0] + s, s);
        d[1][1] = max(d[0][1] + s, d[0][0]);
        d[0][0] = d[1][0], d[0][1] = d[1][1];
        rs = max(max(d[0][0], d[0][1]), rs);
    }
    printf("%d", rs);
}
