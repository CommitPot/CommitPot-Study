#include <stdio.h>

int main() {
    int a[4] = {}, p[101] = {}, r = 0;
    scanf("%d %d %d", a + 1, a + 2, a + 3);
    for (int i = 0, b, c; i < 3; i++) {
        scanf("%d %d", &b, &c);
        for (int j = b; j < c; j++) p[j]++;
    }
    for (int i = 1; i < 101; i++) r += a[p[i]] * p[i];
    printf("%d", r);
}
