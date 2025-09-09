#include <stdio.h>

int main() {
    int a, b, r = 0;
    scanf("%d %d", &a, &b);
    if (a < b) r = b - a;
    else while (a != b) {
            if (a & 1 || a < b) a++;
            else a /= 2;
            r++;
        }
    printf("%d", r);
}
