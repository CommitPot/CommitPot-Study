#include <stdio.h>
#include <string.h>

int main() {
    char s[3];
    scanf("%s", s);
    if (!strcmp(s, "(1)")) printf("0");
    else if (!strcmp(s, ")1(")) printf("2");
    else printf("1");
}
