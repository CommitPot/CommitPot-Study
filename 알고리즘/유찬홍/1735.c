#include <stdio.h>

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int e = b * d / gcd(b, d);
    a *= e / b;
    c *= e / d;
    printf("%d %d", (a + c) / gcd(a + c, e), e / gcd(a + c, e));
    return 0;
}