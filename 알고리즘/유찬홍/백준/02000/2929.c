#include <stdio.h>

int main() {
    int r = 0;
    char s[201];
    scanf("%s", s);
    for (int i = 0, j = 0; s[i]; i++, j++) {
        if (j % 4 != 0 && s[i] < 97) {
            while (j % 4) j++, r++;
        }
    }
    printf("%d", r);
}
