#include <stdio.h>

int main() {
    int n;
    char s[17];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int a = 0;
        for (int j = 0; j < 16; j++) {
            int c = j % 2 ? s[j] - 48 : (s[j] - 48) * 2;
            if (c > 9) c = c / 10 + c % 10;
            a += c;
        }
        printf(a % 10 ? "F\n" : "T\n");
    }
}
