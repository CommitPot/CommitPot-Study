#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    while (r * r <= n) r++;
    printf("%d", --r);
}
