#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a = abs(a) + abs(b);
    printf("%s", (a & 1) == (c & 1) && a <= c ? "YES" : "NO");
}

