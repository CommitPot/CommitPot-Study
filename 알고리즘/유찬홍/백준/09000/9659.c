#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%s", n % 2 == 0 ? "CY" : "SK");
    return 0;
}