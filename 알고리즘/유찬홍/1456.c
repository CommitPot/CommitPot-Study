#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    bool prime[10000001] = {};
    int r = 0;
    long long a, b;
    for (int i = 2; i <= 3163; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 10000000; j += i) {
                prime[j] = 1;
            }
        }
    }
    scanf("%lld %lld", &a, &b);
    int q = sqrt(b);

    for (int i = 2; i <= q; i++) {
        if (!prime[i]) {
            long long j = i;
            while (j <= b / i) {
                j *= i;
                if (a <= j) r++;
            }
        }
    }
    printf("%d", r);
}
