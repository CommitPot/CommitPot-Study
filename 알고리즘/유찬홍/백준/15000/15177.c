#include <stdio.h>

int main() {
    int r[2] = {};
    char s[101];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] > 91) s[i] -= 32;
        if (s[i] == 'K' || s[i] == 'R') r[0]++, r[1]++;
        if (s[i] == 'A' || s[i] == 'O') r[0] += 2;
        if (s[i] == 'N' || s[i] == 'G') r[0]++;
        if (s[i] == 'I') r[1] += 3;
        if (s[i] == 'W' || s[i] == 'B' || s[i] == 'D') r[1]++;
    }
    printf("%s", r[0] == r[1] ? "Feud continues" : r[0] > r[1] ? "Kangaroos" : "Kiwis");
}
