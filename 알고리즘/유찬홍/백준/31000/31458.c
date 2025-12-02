#include <stdio.h>

int main() {
    int n;
    char s[62];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int a = -1, b = 0, c = 0;
        for (int i = 0; s[i]; i++) {
            if (47 < s[i] && s[i] < 50) a = s[i] - 48;
            else if (a > -1) c++;
            else b++;
        }
        printf("%d\n", a ? b & 1 ? 0 : 1 : c ? b & 1 ? 0 : 1 : b & 1 ? 1 : 0);
    }
}
