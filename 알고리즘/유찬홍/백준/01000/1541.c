#include <stdio.h>

int main() {
    int a[25], l = 0, r;
    char s[51];
    scanf("%s", s);
    for (int i = 0, j = 0, k = 0; s[i]; i++) {
        if (47 < s[i] && s[i] < 59) j = j * 10 + s[i] - 48;
        else {
            if (s[i] == '+') k += j;
            else a[l++] = j + k, k = 0;
            j = 0;
        }
        if (!s[i + 1]) a[l++] = j + k;
    }
    r = a[0];
    for (int i = 1; i < l; i++) r -= a[i];
    printf("%d", r);
}
