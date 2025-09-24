#include <stdio.h>

int main() {
    int n, m, d[200001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%s\n", d[a] <= b ? "YES" : "NO");
        if (d[a] <= b) d[a] = c;
    }
}
