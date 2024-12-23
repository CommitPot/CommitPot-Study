#include <stdio.h>

int main() {
    char s[101];
    scanf("%[^\n]", s);
    for (int i = 0; s[i]; i++) {
        printf("%c", s[i]);
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') i += 2;
    }
}
