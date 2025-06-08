#include <stdio.h>

int main() {
    int n, a = 0;
    char s[200001];
    scanf("%d %s", &n, s);
    for (int i = 1; s[i]; i++) {
        if (s[i - 1] == ']' && s[i] == '[') continue;
        if (s[i - 1] < 58 && s[i - 1] == s[i]) a += 2;
        else a++;
    }
    printf("%d", a);
}
