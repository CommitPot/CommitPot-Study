#include <stdio.h>

int main() {
    int n, k, a = 0;
    char t[500001], s[500001];
    scanf("%d %d %s", &n, &k, s);
    for (int i = 0; s[i]; i++) {
        while (a && k && t[a - 1] < s[i]) a--, k--;
        t[a++] = s[i];
    }
    t[a -= k] = 0;
    printf("%s", t);
}
