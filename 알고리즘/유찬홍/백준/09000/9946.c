#include <stdio.h>

int main() {
    char s[1001];
    int b = 1;
    while (scanf("%s", s)) {
        if (s[0] == 69) break;
        int a[27] = {}, r = 0;
        for (int i = 0; s[i]; i++) a[s[i] - 97]++;
        scanf("%s", s);
        for (int i = 0; s[i]; i++) a[s[i] - 97]--;
        for (int i = 0; i < 27; i++) if (a[i]) r = 1;
        printf("Case %d: %s\n", b++, r ? "different" : "same");
    }
}
