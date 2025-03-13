#include <stdio.h>

int main() {
    int n, h, r = 0;
    char s[8];
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int f = 0;
        for (int j = 0; s[j]; j++) f = f * 10 + s[j] - 48;
        h -= f;
        r++;
        if (h < 1) {
            printf("%d", r);
            return 0;
        }
    }
    printf("-1");
}
