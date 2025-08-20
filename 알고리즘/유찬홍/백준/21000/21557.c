#include <stdio.h>

int m(int a, int b) { return a > b ? a : b; }

int main() {
    int n, a, b;
    scanf("%d %d", &n, &a);
    for (int i = 1; i < n - 1; i++) scanf("%*d");
    scanf("%d", &b);
    for (int i = 1; i < n - 2; i++) {
        if (a < b) b--;
        else a--;
    }
    printf("%d", m(--a, --b));
}
