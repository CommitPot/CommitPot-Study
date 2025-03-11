#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, r;
    scanf("%d %d %d", &a, &b, &c);
    if (a && b) r = sqrt(a + b);
    else if (a && c) r = c * c - a;
    else r = c * c - b;
    printf("%d", r);
}
