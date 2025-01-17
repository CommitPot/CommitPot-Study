#include <stdio.h>

int main() {
    int n, a, b, r = 4;
    scanf("%d %d %d", &n, &a, &b);
    if (a == 1 || a == n) r--;
    if (b == 1 || b == n) r--;
    printf("%d", n > 1 ? r : 0);
}
