#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t, a, r = 0, b[33] = {};
    scanf("%d %d", &n, &t);
    for (int i = 1, j = 0; i <= t; i++) if (!(t % i)) b[j++] = i;
    while (n--) {
        scanf("%d", &a);
        int c = 1e9;
        for (int i = 0; b[i]; i++) {
            if (abs(a - b[i]) < c) c = abs(a - b[i]);
        }
        r += c;
    }
    printf("%d", r);
}
