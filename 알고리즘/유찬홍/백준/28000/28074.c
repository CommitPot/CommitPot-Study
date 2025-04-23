#include <stdio.h>

int main() {
    int a[5] = {}, r = 0;
    char s[101];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'M') a[0]++;
        if (s[i] == 'O') a[1]++;
        if (s[i] == 'B') a[2]++;
        if (s[i] == 'I') a[3]++;
        if (s[i] == 'S') a[4]++;
    }
    for (int i = 0; i < 5; i++) r += a[i] > 0;
    printf("%s", r > 4 ? "YES" : "NO");
}
