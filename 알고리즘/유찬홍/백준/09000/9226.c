#include <stdio.h>

int main() {
    char s[21];
    while (scanf("%s", s), s[0] != '#') {
        int i = 0;
        for (; s[i]; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') break;
        }
        for (int j = i; s[j]; j++) printf("%c", s[j]);
        for (int j = 0; j < i; j++) printf("%c", s[j]);
        printf("ay\n");
    }
}
