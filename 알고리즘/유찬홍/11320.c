#include <stdio.h>
#include <math.h>

int main() {
    int t, a, b;
    double d = sqrt(3) / 4;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%.0lf\n", d * a * a / (d * b * b));
    }
}
