#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    long long int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        if (!i) sum += b;
        else sum += abs(a - b);
        sum += b * 2;
        a = b;
    }
    printf("%lld", sum + n * 2 + b);
}
