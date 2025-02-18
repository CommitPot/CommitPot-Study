#include <stdio.h>

int main() {
    int n;
    char *f = "22233344455566677778889999";
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[41], r[41];
        scanf("%s", s);
        for (int j = 0, k = 0; k < 12; j++) {
            if (s[j] == '-') continue;
            if (s[j] > 47 && s[j] < 58) r[k++] = s[j];
            else r[k++] = f[s[j] - 65];
            if (k == 3 || k == 7) r[k++] = '-';
        }
        printf("%s\n", r);
    }
}
