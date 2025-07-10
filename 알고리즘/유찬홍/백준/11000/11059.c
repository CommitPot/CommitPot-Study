#include <stdio.h>

int main() {
    int a[1002] = {}, r = 0, l;
    char s[1001];
    scanf("%s", s);
    for (l = 1; s[l - 1]; l++) a[l] = s[l - 1] - 48 + a[l - 1];
    for (int i = 1; i < l; i++) {
        for (int j = i; j < l; j++) {
            if (j - i + 1 & 1) continue;
            int m = (i + j) / 2;
            if (a[j] - a[m] == a[m] - a[i - 1]) {
                r = r < j - i + 1 ? j - i + 1 : r;
            }
        }
    }
    printf("%d", r);
}
