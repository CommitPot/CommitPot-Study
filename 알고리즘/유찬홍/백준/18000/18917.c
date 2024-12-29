#include <stdio.h>

int main() {
    int n;
    long long s = 0, k = 0;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d", &a);
        if (a > 2) printf("%lld\n", a == 3 ? s : k);
        else {
            scanf("%d", &b);
            s = (a == 1) ? s + b : s - b;
            k ^= b;
        }
    }
}
