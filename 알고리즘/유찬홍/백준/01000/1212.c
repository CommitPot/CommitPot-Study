#include <stdio.h>

int main() {
    int l = 0;
    char s[333335], r[1000006] = "0";
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        for (int j = 4, k = s[i] - 48; j; j >>= 1) {
            if (k / j) r[l++] = 49;
            else if (l) r[l++] = 48;
            k %= j;
        }
    }
    printf("%s", r);
}
