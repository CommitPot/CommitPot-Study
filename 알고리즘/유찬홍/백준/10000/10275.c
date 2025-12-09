#include <math.h>
#include <stdio.h>

int main() {
    int t, n;
    long long a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld %lld", &n, &a, &b);
        long long c = pow(2, n), r = 0;
        while (a) {
            if (a >= c) a -= c;
            c /= 2;
            r++;
        }
        printf("%lld\n", --r);
    }
}
