#include <stdio.h>
#include <math.h>

int main() {
    double a;
    while (1) {
        scanf("%lf", &a);
        if (a == 0) break;
        double sum = 1;
        for (int i = 1; i <= 4; i++) {
            sum += pow(a, i);
        }
        printf("%.2lf\n", sum);
    }
}
