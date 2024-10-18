#include <stdio.h>

int main() {
    char s[20];
    scanf("%s", s);
    for (int i = 1, j = s[1] - s[0]; s[i]; i++) {
        if (j != s[i] - s[i - 1]) s[0] = 0;
        j = s[i] - s[i - 1];
    }
    printf("%s", s[0] ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>");
}
