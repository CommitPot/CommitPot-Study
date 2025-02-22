#include<stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        char s[101];
        int a[26] = {};
        scanf(" %[^\n]", s);
        for (int i = 0; s[i]; i++) {
            if (s[i] > 64 && s[i] < 91) a[s[i] - 65]++;
            if (s[i] > 96 && s[i] < 123) a[s[i] - 97]++;
        }
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (!a[i]) c = 1;
        }
        if (c) {
            printf("missing ");
            for (int i = 0; i < 26; i++) {
                if (!a[i]) printf("%c", i + 97);
            }
            printf("\n");
        } else printf("pangram\n");
    }
}
