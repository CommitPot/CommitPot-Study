#include <stdio.h>
#include <stdlib.h>

int g(int a, int b) {
    return b ? g(b, a % b) : a;
}

int main() {
    int n, s, r = 0, k;
    scanf("%d %d", &n, &s);
    while (n--) {
        scanf("%d", &k);
        r = g(abs(s - k), r);
    }
    printf("%d", r);
}
