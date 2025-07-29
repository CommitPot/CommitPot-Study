#include <stdio.h>

int main() {
    int n, r = 0, k = 35;
    scanf("%d", &n);
    while (n--) r += k, k += 35;
    printf("%d", r);
}
