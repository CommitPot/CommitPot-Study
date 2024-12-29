#include <stdio.h>

int main() {
    char s[5];
    scanf("%s", s);
    printf("%c", s[0] == 'I' ? 'E' : 'I');
    printf("%c", s[1] == 'S' ? 'N' : 'S');
    printf("%c", s[2] == 'T' ? 'F' : 'T');
    printf("%c", s[3] == 'J' ? 'P' : 'J');
}
