#include <stdio.h>

int f(int x) { return (1 + x) * x / 2; }

int main() {
    int n, a, r[80001] = {};
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (!r[a]) r[a] = f(a / 3) * 3 + f(a / 7) * 7 - f(a / 21) * 21;
        printf("%d\n", r[a]);
    }
}
