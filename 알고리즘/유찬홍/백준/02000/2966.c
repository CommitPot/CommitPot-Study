#include <stdio.h>

int main() {
    int n, a[3] = {};
    char s[101];
    scanf("%d %s", &n, s);
    for (int i = 0; s[i]; i++) {
        if (i % 3 == s[i] - 65) a[0]++;
        if ((i & 1 ? i % 4 == 1 ? 0 : 2 : 1) == s[i] - 65) a[1]++;
        if ((i % 6 < 2 ? 2 : i % 6 < 4 ? 0 : 1) == s[i] - 65) a[2]++;
    }
    int x = a[0] < a[1] ? a[2] < a[1] ? a[1] : a[2] : a[0] > a[2] ? a[0] : a[2];
    printf("%d\n", x);
    for (int i = 0; i < 3; i++) {
        if (x <= a[i]) {
            printf("%s\n", !i ? "Adrian" : i == 1 ? "Bruno" : "Goran");
        }
    }
}
