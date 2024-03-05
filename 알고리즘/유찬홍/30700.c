#include <stdio.h>

int main() {
    char s[1001], a[] = "KOREA";
    scanf("%s", s);
    int c = 0;
    for (int i = 0, b = 0; s[i] != 0; i++) {
        if (s[i] == a[b]) c++, b = (b + 1) % 5;
    }
    printf("%d", c);
}
