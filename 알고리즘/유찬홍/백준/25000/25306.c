#include <stdio.h>

#define ll long long

int main() {
    ll a, b, c = 1;
    scanf("%lld %lld", &a, &b);
    c = a & 1 ? a : c;
    for (ll i = b - (b - a) % 4 + (a & 1 ? 1 : -2); i <= b; i++) c ^= i;
    printf("%lld", c);
}
