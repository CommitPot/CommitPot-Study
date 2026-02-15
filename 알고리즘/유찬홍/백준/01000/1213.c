#include <stdio.h>

int main() {
    int a[26] = {}, l = 0, w = 0;
    char s[500001];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) a[s[i] - 65]++;
    for (int i = 0; i < 26; i++) {
        if (a[i] & 1) {
            if (w) {
                printf("I'm Sorry Hansoo");
                return 0;
            }
            w = i + 65;
            a[i]--;
        }
    }
    for (int i = 0; i < 52; i++) {
        int x = (i > 25 ? 51 - i : i) % 26;
        for (int j = a[x] / 2; j; j--) {
            s[l++] = x + 65;
        }
        if (w && i == 25) s[l++] = w;
    }
    printf("%s", s);
}
