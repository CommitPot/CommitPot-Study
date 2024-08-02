#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    char s[101];
    scanf("%s", s);
    int l = strlen(s), k = 0;
    int q = sqrt(l);
    for (int i = 1; i <= q; i++) k = l % i ? k : i;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < l; j += k) {
            printf("%c", s[j]);
        }
    }
}
