#include <stdio.h>

int main() {
    int a[16][2] = {};
    char s[17];
    scanf("%s %s", s, &s[8]);
    for (int i = 0; i < 8; i++) {
        a[i * 2][0] = s[i] - 48;
        a[i * 2 + 1][0] = s[i + 8] - 48;
    }
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 15 - i; j++) {
            a[j][1] = (a[j][0] + a[j + 1][0]) % 10;
        }
        for (int j = 0; j < 15 - i; j++) {
            a[j][0] = a[j][1];
        }
    }
    printf("%02d", a[0][0] * 10 + a[1][0]);
}
