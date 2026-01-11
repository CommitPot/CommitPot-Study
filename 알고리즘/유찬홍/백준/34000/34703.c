#include <stdio.h>

int main() {
    int n, a = 0;
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        a |= 1 << j;
    }
    printf("%s", a == 62 ? "NO" : "YES");
}
