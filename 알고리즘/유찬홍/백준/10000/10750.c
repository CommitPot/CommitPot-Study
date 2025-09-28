#include <stdio.h>
#include <string.h>

int main() {
    int p = 0;
    char s[1000001], t[101], st[1000001];
    scanf("%s %s", s, t);
    int l = strlen(t);
    for (int i = 0; s[i]; i++) {
        st[p++] = s[i];
        st[p] = 0;
        while (p >= l && !strcmp(&st[p - l], t)) p -= l;
    }
    st[p] = 0;
    printf("%s", st);
}
