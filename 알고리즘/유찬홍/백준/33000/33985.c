#include <stdio.h>

int main() {
    int n;
    char s[300001];
    scanf("%d %s", &n, s);
    printf("%s", s[0] == 65 && s[n - 1] == 66 ? "Yes" : "No");
}
