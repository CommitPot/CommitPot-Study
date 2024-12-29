#include <stdio.h>

int main() {
    int n, m, s = 0, c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        if (s + a > m) c++, s = a;
        else s += a;
    }
    printf("%d", c + (s > 0));
}
