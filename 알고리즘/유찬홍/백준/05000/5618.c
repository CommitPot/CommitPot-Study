#include <stdio.h>

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n, arr[4];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n == 2) {
        int c = gcd(arr[0], arr[1]);
        for (int i = 1; i <= c; i++) {
            if (c % i == 0) printf("%d\n", i);
        }
    } else {
        int c = gcd(arr[0], arr[1]);
        int d = gcd(arr[1], arr[2]);
        int e = gcd(c, d);
        for (int i = 1; i <= e; i++) {
            if (e % i == 0) printf("%d\n", i);
        }
    }
    return 0;
}