#include <stdio.h>

int main() {
    int a, d, k;
    scanf("%d %d %d", &a, &d, &k);
    if ((k - a) % d || (k - a) / d < 0) printf("X");
    else printf("%d", (k - a) / d + 1);
    return 0;
}