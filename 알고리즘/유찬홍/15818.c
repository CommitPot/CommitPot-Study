#include <stdio.h>

int main() {
    int n, m, r = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        r = (long long) r * j % m;
    }
    printf("%d", r);
}
