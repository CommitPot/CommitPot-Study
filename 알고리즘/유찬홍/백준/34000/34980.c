#include <stdio.h>

int main() {
    int n, a = 1, b[2] = {};
    char s[2][151];
    scanf("%d %s %s", &n, s[0], s[1]);
    for (int i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) a = 0;
        b[0] += s[0][i] == 'w';
        b[1] += s[1][i] == 'w';
    }
    if (b[0] == b[1]) printf("%s", a ? "Good" : "Its fine");
    else printf("%s", b[0] < b[1] ? "Manners maketh man" : "Oryang");
}
