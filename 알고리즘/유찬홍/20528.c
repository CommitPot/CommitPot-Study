#include <stdio.h>

int main() {
    int n;
    char s[101], a = 0, b = 1;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (!a) a = s[0];
        else if (s[0] != a) b = 0;
    }
    printf("%d", b);
}
