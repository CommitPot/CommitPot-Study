#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[20], b[10], c[20], d[10];
    scanf("%s %s %s %s", a, b, c, d);
    strcat(a, b);
    strcat(c, d);
    long long int e = atoll(a) + atoll(c);
    printf("%lld", e);
}
