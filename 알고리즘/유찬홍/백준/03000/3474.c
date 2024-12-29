#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int c = 0;
        for (int i = 5; i <= n; i *= 5) c += n / i;
        printf("%d\n", c);
    }
}
