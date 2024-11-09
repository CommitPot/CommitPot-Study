#include <stdio.h>
#include <math.h>

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.0lf", n ? ceil(log2(n)) + 1 : 0);
}
