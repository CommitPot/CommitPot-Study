#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    while (scanf(" %[^\n]", s), strcmp(s, "EOI")) {
        for (int i = 0; s[i]; i++) {
            if (97 > s[i] || 122 < s[i]) s[i] += 32;
        }
        printf("%s\n", strstr(s, "nemo") ? "Found" : "Missing");
    }
}
