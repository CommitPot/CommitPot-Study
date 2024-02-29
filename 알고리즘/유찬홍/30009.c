#include <stdio.h>

int main() {
    int n, x, y, r, a, b = 0, c = 0;
    scanf("%d %d %d %d", &n, &x, &y, &r);
    while (n--) {
        scanf("%d", &a);
        if (x + r == a || x - r == a) c++;
        if (x + r > a && x - r < a) b++;
    }
    printf("%d %d", b, c);
}
