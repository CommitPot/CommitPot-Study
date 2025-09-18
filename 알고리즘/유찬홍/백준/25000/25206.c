#include <stdio.h>

int main() {
    double k, r = 0, p = 0, i = 20;
    char s[2];
    while (i--) {
        scanf("%*s %lf %s", &k, s);
        if (*s == 'P') continue;
        r += k;
        p += k * (*s == 70 ? 0 : 4 - *s + 65 + (s[1] == 48 ? 0 : .5));
    }
    printf("%lf", p / r);
}
