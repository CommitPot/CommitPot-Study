#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%.0lf", pow(2, n) - pow(2, abs(a + b - n)));
}
