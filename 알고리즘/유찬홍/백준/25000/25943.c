#include <stdio.h>

int main() {
    int n, a[2] = {}, b[] = {100, 50, 20, 10, 5, 2, 1}, r = 0;
    scanf("%d", &n);
    for (int i = 0, c; i < n; i++) {
        scanf("%d", &c);
        a[a[0] > a[1]] += c;
    }
    while (a[0] != a[1]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 7; j++) {
                int k = a[!i] - a[i];
                if (k >= b[j]) {
                    r += k / b[j];
                    a[i] += k / b[j] * b[j];
                }
            }
        }
    }
    printf("%d", r);
}
