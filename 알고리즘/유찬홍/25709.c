#include <stdio.h>

int main() {
    int a, c = 0;
    scanf("%d", &a);
    while (a) {
        int b = a, d = 1, e = 0;
        while (b) {
            if (b % 10 == 1) e = d;
            b /= 10, d *= 10;
        }
        if (e) a = a / (e * 10) * e + a % e;
        else a--;
        c++;
    }
    printf("%d", c);
}
