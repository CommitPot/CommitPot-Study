#include <stdio.h>

#define f(c, d) if (a + b == c && (a == d || b == d)) r++;

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        f(4, 1)
        f(7, 4)
        f(5, 4)
    }
    printf("%s", r == 3 && n == 3 ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
}
