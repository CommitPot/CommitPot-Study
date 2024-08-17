#include <stdio.h>
#include <string.h>

int main() {
    int n, m = 5, a;
    char r[11], k[11];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d", k, &a);
        if (m > a) m = a, strcpy(r, k);
    }
    printf("%s", r);
}
