#include <stdio.h>

int main() {
    int a[2] = {};
    char s[100001];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'U' || s[i] == 'C') a[0]++;
        if (s[i] == 'D' || s[i] == 'P') a[1]++;
    }
    printf("%s%s", a[0] > (a[1] + 1) / 2 ? "U" : "", a[1] ? "DP" : "");
}
