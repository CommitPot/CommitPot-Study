#include <stdio.h>
#include <math.h>

int main() {
    int n, p, r = 0, a[236197] = {};
    scanf("%d %d", &n, &p);
    a[n] = 1;
    do {
        int k = 0;
        while (n) {
            k += pow(n % 10, p);
            n /= 10;
        }
        a[k]++;
        n = k;
    } while (a[n] <= 2);
    for (int i = 0; i < 236197; i++) if (a[i] == 1) r++;
    printf("%d", r);
}
