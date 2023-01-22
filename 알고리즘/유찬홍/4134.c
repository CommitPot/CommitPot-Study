#include <stdio.h>
#include <math.h>

typedef long long int lli;

lli is_prime(lli n) {
    if (n <= 1) return 0;
    lli len = sqrt(n);
    for (lli i = 2; i <= len; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int t;
    lli n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld", &n);
        while (1) {
            if (is_prime(n)) {
                printf("%lld\n", n);
                break;
            }
            n++;
        }
    }
    return 0;
}