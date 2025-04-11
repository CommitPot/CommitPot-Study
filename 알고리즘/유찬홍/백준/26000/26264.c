#include <stdio.h>

int main() {
    int a[2] = {};
    char s[800001];
    scanf("%*d %s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'b') a[0]++, i += 6;
        else a[1]++, i += 7;
    }
    printf("%s", a[0] == a[1] ? "bigdata? security!" : a[0] > a[1] ? "bigdata?" : "security!");
}
