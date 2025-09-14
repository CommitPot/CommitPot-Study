#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    char c[101];
    scanf("%d %d %s", &a, &b, c);
    printf("%d", a ^ b * (c[strlen(c) - 1] - 48 & 1));
}
