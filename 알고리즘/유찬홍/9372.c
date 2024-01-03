#include <stdio.h>

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        while (m--) scanf("%*d %*d");
        printf("%d\n", n - 1);
    }
}
