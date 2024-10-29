#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[101], w[20][21];
    scanf("%s %d", s, &n);
    for (int i = 0; i < n; i++) scanf("%s", w[i]);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; s[j]; j++) {
            s[j]++;
            if (s[j] > 122) s[j] -= 26;
        }
        for (int j = 0; j < n; j++) {
            if (strstr(s, w[j])) {
                printf("%s", s);
                return 0;
            }
        }
    }
}
