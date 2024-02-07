#include <stdio.h>

int main() {
    int a, b, c, i = 1;
    scanf("%d %d %d", &a, &b, &c);
    while (a) {
        printf("Case %d: %d\n", i++, (c / b) * a + (c % b > a ? a : c % b));
        scanf("%d %d %d", &a, &b, &c);
    }
}
