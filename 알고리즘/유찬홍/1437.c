#include <stdio.h>

int main() {
    int n, c = 1;
    scanf("%d", &n);
    if (n == 0) printf("0");
    else if (n == 1) printf("1");
    else {
        if (n % 3 == 1) {
            for (int i = 0; i < n / 3 - 1; i++) c = c * 3 % 10007;
            printf("%d", c * (n % 3 + 3) % 10007);
        } else {
            for (int i = 0; i < n / 3; i++) c = c * 3 % 10007;
            printf("%d", c * (n % 3 ? n % 3 : 1) % 10007);
        }
    }
}
