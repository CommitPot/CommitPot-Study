#include <stdio.h>

int main() {
    int n, m, r = 1;
    scanf("%d %d", &n, &m);
    while (n * r++ % m != 1);
    printf("%d", --r);
}
