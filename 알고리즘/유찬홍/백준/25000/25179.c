#include <stdio.h>

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("Can%s win", (n - 1) % (m + 1) ? "" : "'t");
}
