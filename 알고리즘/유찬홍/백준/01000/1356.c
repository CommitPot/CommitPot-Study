#include <stdio.h>

int main() {
    char s[11];
    scanf("%s", s);
    for (int i = 1; s[i]; i++) {
        int l = 1, r = 1;
        for (int j = 0; j < i; j++) l *= s[j] - 48;
        for (int j = i; s[j]; j++) r *= s[j] - 48;
        if (l == r) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
