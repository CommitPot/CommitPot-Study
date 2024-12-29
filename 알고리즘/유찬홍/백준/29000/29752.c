#include <stdio.h>

int main() {
    int n, r = 0, v = 0;
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        if (j) v++;
        else r = r < v ? v : r, v = 0;
    }
    printf("%d", r > v ? r : v);
}
