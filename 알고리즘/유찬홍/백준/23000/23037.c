#include <stdio.h>
#include <math.h>

int main() {
    int r = 0;
    char s[6];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) r += pow(s[i] - 48, 5);
    printf("%d", r);
}
