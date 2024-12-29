#include <stdio.h>

int main() {
    char s[9];
    while (scanf("%s", s)) {
        int l = 0, k = 0;
        for (int i = 1; i < 8; i++) {
            if (s[i - 1] == s[i]) k++;
            else l = l > k ? l : k, k = 0;
        }
        printf("%d\n", (l > k ? l : k) + 1);
    }
}
