#include <stdio.h>

int f(int a, int b) {
    return b ? f(b, a % b) : a;
}

int main() {
    int n, a[500001], v, c = 0;
    double r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &v);
    for (int i = 0; i < n; i++) {
        if (f(v, a[i]) == 1) r += a[i], c++;
    }
    printf("%lf", r / c);
}
