#include <stdio.h>

int main() {
    long long r = 0, k = 0;
    char s[1000001];
    scanf("%*d %s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '2') k++;
        else k = 0;
        r += k * (k + 1) / 2;
    }
    printf("%lld", r);
}
