#include <stdio.h>

int main() {
    char a[1001], b[1001], f[2001];
    while (gets(a) && gets(b)) {
        int c[26] = {}, d[26] = {}, e = 0;
        for (int i = 0; a[i]; i++) c[a[i] - 97]++;
        for (int i = 0; b[i]; i++) d[b[i] - 97]++;
        for (int i = 0; i < 26; i++) {
            int g = c[i] < d[i] ? c[i] : d[i];
            while (g--) f[e++] = i + 97;
        }
        f[e] = 0;
        printf("%s\n", f);
    }
}
