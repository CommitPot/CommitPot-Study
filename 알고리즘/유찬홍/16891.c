#include <stdio.h>

double g(double n) {
    return (1 - n * n) / (1 + n * n);
}

int main() {
    int r = 0;
    double n, a = 0, b = -100;
    scanf("%lf", &n);
    while (1) {
        double c = g(n) * a + n * n * 2 / (1 + n * n) * b;
        double d = 2 / (1 + n * n) * a - g(n) * b;
        a = c, b = d;
        r++;
        if (a < 0 && a < b) a *= -1, r++;
        if (a > 0 && b > 0 && a < b) break;
        if (!a && b > 0) break;
        if (!a && !b) break;
    }
    printf("%d", r);
}
