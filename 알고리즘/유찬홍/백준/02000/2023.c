#include <stdio.h>
#include <math.h>

int num;

int checkPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void amazingPrime(int n, int count) {
    if (checkPrime(n) && count == num) {
        printf("%d\n", n);
        return;
    }
    for (int i = 1; i <= 9; i += 2) {
        if (checkPrime(n * 10 + i)) amazingPrime(n * 10 + i, count + 1);
    }
}

int main() {
    scanf("%d", &num);
    for (int i = 2; i <= 7; i++) {
        if (checkPrime(i)) amazingPrime(i, 1);
    }
}