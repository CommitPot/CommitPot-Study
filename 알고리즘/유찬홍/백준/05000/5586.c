#include <stdio.h>

int main() {
    int a = 0, b = 0;
    char s[10001];
    scanf("%s", s);
    for (int i = 0; s[i + 2]; i++) {
        if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') a++;
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') b++;
    }
    printf("%d\n%d", a, b);
}
