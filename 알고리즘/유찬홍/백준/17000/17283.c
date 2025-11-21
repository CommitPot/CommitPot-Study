#include <stdio.h>
#include <math.h>

int main() {
    int i = 2, v = 0;
    double n, r;
    scanf("%lf %lf", &n, &r);
    while (floor(r * n / 100) > 5.0) {
        n = floor(r * n / 100);
        v += (int) n * i;
        i *= 2;
    }
    printf("%d", v);
}
