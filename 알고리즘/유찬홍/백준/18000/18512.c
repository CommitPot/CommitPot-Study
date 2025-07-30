#include <stdio.h>

int main() {
    int x, y, a, b, c[10001] = {}, r = -1;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    for (int i = a; i < 10001; i+= x) c[i] = 1;
    for (int i = b; i < 10001; i += y) {
        if (c[i]) {
            r = i;
            break;
        }
    }
    printf("%d", r);
}
