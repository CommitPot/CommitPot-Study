#include <stdio.h>

int main() {
    char s[101], *a = "eplragfsoxvcwtibzdhnykmjuq", *b = "EPLRAGFSOXVCWTIBZDHNYKMJUQ";
    while (gets(s)) {
        for (int i = 0; s[i]; i++) {
            if (s[i] > 64 && s[i] < 91) s[i] = b[s[i] - 65];
            if (s[i] > 96 && s[i] < 123) s[i] = a[s[i] - 97];
        }
        printf("%s\n", s);
    }
}
