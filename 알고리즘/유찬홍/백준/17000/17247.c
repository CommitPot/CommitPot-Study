#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, a, x = 0, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            if (a) {
                if (!x) x = i, y = j;
                else x = abs(x - i), y = abs(y - j);
            }
        }
    }
    printf("%d", x + y);
}
