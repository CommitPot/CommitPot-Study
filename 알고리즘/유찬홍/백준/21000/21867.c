#include <stdio.h>

int main() {
    int k = 0;
    char s[200001];
    scanf("%*d %s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'J' || s[i] == 'A' || s[i] == 'V') continue;
        s[k++] = s[i];
    }
    s[k] = 0;
    printf("%s", k ? s : "nojava");
}
