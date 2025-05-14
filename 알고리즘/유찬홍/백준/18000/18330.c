#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", n > k + 60 ? (n - k - 60) * 3000 + (k + 60) * 1500 : n * 1500);
}
