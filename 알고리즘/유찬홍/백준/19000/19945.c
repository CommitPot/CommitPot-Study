#include <stdio.h>

int main() {
    int n, r = 31;
    scanf("%d", &n);
    n += !n;
    while (~n & 1 << r) r--;
    printf("%d", r + 1);
}
