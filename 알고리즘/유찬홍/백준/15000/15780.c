#include <stdio.h>

int main() {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < m; i++) {
        scanf("%d", &j);
        r += j / 2 + j % 2;
    }
    printf("%s", r >= n ? "YES" : "NO");
}
