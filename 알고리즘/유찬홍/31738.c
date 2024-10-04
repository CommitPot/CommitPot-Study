#include <stdio.h>

int main() {
    long long n, m, r = 1;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= (n < m ? n : m); i++) r = r * i % m;
    printf("%lld", r);
}
