#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a;
    char s[9];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        a = 0;
        for (int k = 0; k < 3; k++) {
            a += (s[k] - 65) * pow(26, 3 - k - 1);
        }
        printf("%snice\n", abs(atoi(&s[4]) - a) > 100 ? "not " : "");
    }
}
