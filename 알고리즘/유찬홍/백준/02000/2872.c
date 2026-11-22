#include <stdio.h>

int main() {
    int n, a = 0, v = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1, j; i < n; i++) {
        scanf("%d", &j);
        if (a < j) a = j;
        if (a > j && v < j) v = j;
    }
    printf("%d", v);
}
