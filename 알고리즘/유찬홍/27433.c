#include <stdio.h>

int main() {
    int n;
    long long int a = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a *= i;
    }
    printf("%lld", a);
    return 0;
}