#include <stdio.h>

int main() {
    int t, n, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &c);
        printf("%d\n", n / c + !!(n % c));
    }
}
