#include <stdio.h>

int main() {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, j = n; i < 18; i++) {
        r += j / m;
        j /= m;
    }
    printf("%d", n + r);
}
