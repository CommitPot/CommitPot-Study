#include <stdio.h>

int main() {

    int n = 0;
    long long int sum = 1;

    scanf("%lld", &n);

    for(int i=n; i>=1; i--) {
        sum *= i;
    }

    printf("%lld", sum);
}
