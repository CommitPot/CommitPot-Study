#include <stdio.h>

int main() {
    int n, rs = 0;
    char s[10011];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int r = 0;
        for (int j = 0; s[j]; j++) {
            if (s[j] == 'f' && s[j + 1] == 'o' && s[j + 2] == 'r') r++;
            if (s[j] == 'w' && s[j + 1] == 'h' && s[j + 2] == 'i' && s[j + 3] == 'l' && s[j + 4] == 'e') r++;
        }
        rs = r > rs ? r : rs;
    }
    printf("%d", rs);
}
