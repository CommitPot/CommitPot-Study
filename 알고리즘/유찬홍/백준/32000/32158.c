#include <stdio.h>

int main() {
    int n, a[2] = {};
    char s[101];
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
        a[0] += s[i] == 'P';
        a[1] += s[i] == 'C';
    }
    a[0] = a[1] = a[0] < a[1] ? a[0] : a[1];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P' && a[0]-- > 0) s[i] = 'C';
        else if (s[i] == 'C' && a[1]-- > 0) s[i] = 'P';
    }
    printf("%s", s);
}
