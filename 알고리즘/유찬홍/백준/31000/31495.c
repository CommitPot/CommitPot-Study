#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    scanf("%[^\n]", s);
    int l = strlen(s);
    if (*s != '\"' || s[l - 1] != '\"' || l < 3) printf("CE");
    else {
        s[l - 1] = 0;
        printf("%s", &s[1]);
    }
}
