#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n <= k) printf("0");
    else if (n - 1 == k || !(k & 1)) printf("%d", n);
    else printf("%d", n / 2 * 2);
}
