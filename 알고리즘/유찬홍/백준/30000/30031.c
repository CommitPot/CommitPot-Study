#include <stdio.h>

int main() {
    int n, a, r = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %*d", &a);
        if (a == 136) r += 1000;
        if (a == 142) r += 5000;
        if (a == 148) r += 10000;
        if (a == 154) r += 50000;
    }
    printf("%d", r);
}
