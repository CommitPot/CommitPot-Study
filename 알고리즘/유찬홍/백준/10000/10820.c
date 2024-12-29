#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    while (gets(s) != '\0') {
        int l = strlen(s), arr[4] = {0};
        while (l--) {
            if (s[l] == ' ') arr[3]++;
            else if (s[l] > 47 && s[l] < 58) arr[2]++;
            else if (s[l] > 64 && s[l] < 91) arr[1]++;
            else arr[0]++;
        }
        for (int i = 0; i < 4; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
