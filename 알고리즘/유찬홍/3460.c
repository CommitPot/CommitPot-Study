#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int c = 0;
        while (n) {
            int m = n % 2;
            n /= 2;
            if (m) printf("%d ", c);
            c++;
        }
    }
    return 0;
}