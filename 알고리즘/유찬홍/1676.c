#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        if (i % 5 == 0) {
            n = i, c++;
            while (!(n / 5 % 5)) n /= 5, c++;
        }
    }
    printf("%d", c);
}
