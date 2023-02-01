#include <stdio.h>

int main() {
    long long int N = 0;

    scanf("%lld", &N);

    while (N > 1) {
        for (int i = 2; i <= N; i++) {
            if (N % i == 0) {
                printf("%d\n", i);
                N /= i;
                break;
            }
        }
    }
}
