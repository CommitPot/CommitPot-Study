#include <stdio.h>

int main() {
    char a[] = "qwertyuiopasdfghjklzxcvbnm", s[1001];
    scanf("%*d %[^\n]", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 32) continue;
        s[i] = a[s[i] - 97];
    }
    printf("%s", s);
}
