#include <stdio.h>

int main() {
    char s[51];
    scanf("%*d %s", &s[1]);
    for (int i = 1; s[i]; i++) {
        if (s[i] == 'S' && s[i - 1] == 'P') {
            while (s[++i] > 51 && s[i] < 54);
            printf("S"), i--;
        } else printf("%c", s[i]);
    }
}
