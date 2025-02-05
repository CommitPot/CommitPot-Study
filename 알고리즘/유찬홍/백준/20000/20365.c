#include <stdio.h>

int main() {
    int a[2] = {}, f;
    char s[500001];
    scanf("%*d %s", s);
    f = s[0] < 67;
    for (int i = 0; s[i];) {
        while (s[++i] < 67 == f && s[i]);
        a[s[i - 1] < 67]++;
        f = !f;
    }
    printf("%d", (a[0] < a[1] ? a[0] : a[1]) + 1);
}
