#include <stdio.h>
#include <math.h>

int main() {
    char s[31];
    int n, v = 0, l = scanf("%d %s", &n, s);
    int k = pow(2, n + 1) - 1;
    if (l < 2) goto o;
    for (int i = 0; s[i]; i++) {
        k = k - v;
        v += v;
        if (s[i] == 'L') k--, v += 1;
        else k -= 2, v += 2;
    }
    o:
    printf("%d", k);
}
