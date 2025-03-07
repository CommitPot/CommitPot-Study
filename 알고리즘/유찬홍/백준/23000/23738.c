#include <stdio.h>

int main() {
    char s[101];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        printf("%s", s[i] == 'B' ? "v" :s[i] == 'E' ? "ye" :
        s[i] == 'H' ? "n" : s[i] == 'P' ? "r" : s[i] == 'C' ? "s" :
        s[i] == 'Y' ? "u" : s[i] == 'X' ? "h" : (char[]) {s[i] + 32,0});
    }
}
