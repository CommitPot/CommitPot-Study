#include <stdio.h>

int main() {
    int n, a, r = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1, b, c = 1; i < n; i++) {
        scanf("%d", &b);
        if (a + c != b) {
            r += a;
            c = 1;
            a = b;
        } else c++;
    }
    printf("%d", r + a);
}
