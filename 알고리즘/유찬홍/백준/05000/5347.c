#include <stdio.h>
typedef long long int llint;
llint gcd(llint a, llint b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    llint n, a, b;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a * b / gcd(a, b));
    }
    return 0;
}