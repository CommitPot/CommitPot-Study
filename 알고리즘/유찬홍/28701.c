#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s = n * (n + 1) / 2;
    printf("%d\n%d\n%d", s, s * s, s * s);
}
