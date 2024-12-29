#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int c = 1;
        while (c * c <= n) c++;
        printf("%d\n", --c);
    }
}
