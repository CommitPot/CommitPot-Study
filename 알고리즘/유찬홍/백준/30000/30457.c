#include <stdio.h>

int main() {
    int n, a[1001] = {}, b, r = 0;
    scanf("%d", &n);
    while (n--) scanf("%d", &b), a[b]++;
    for (int i = 1; i < 1001; i++) r += a[i] > 2 ? 2 : a[i];
    printf("%d", r);
}
