#include <stdio.h>

int main() {
    double a, b, v = 0;
    int r = 0;
    for (int i = 3; i; i--) {
        scanf("%lf %lf", &a, &b);
        double x = b * 10 / (a * 10 - (a < 500 ? 0 : 500));
        if (v < x) {
            v = x;
            r = i;
        }
    }
    printf("%c", r & 1 ? r > 1 ? 'S' : 'U' : 'N');
}
