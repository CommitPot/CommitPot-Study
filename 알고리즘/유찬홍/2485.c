#include <stdio.h>

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int n, a, b, c, d;
    scanf("%d %d %d", &n, &a, &b);
    d = a, a = b - a, n--;
    for (int i = 1; i < n; i++) {
        scanf("%d", &c);
        a = gcd(a, c - b);
        b = c;
    }
     printf("%d", (b - d) / a - n);
}
