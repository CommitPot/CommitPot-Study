#include <stdio.h>
#include <string.h>

int main() {
    int i = 2, k = 0;
    char s[10001], r[50000];
    while (scanf("%s", s), s[1] != 97) {
        int l = strlen(s);
        for (int j = 0; j < l; j += i) r[k++] = s[j];
        r[k++] = 10, i++;
    }
    printf("%s", r);
}
