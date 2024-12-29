#include <stdio.h>

int main() {
    int n, s, a, c = 0, t = 0;
    scanf("%d %d", &n, &s);
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        if (a > s) s = a, t = 0;
        else t++;
        c = c < t ? t : c;
    }
    printf("%d", c);
}
