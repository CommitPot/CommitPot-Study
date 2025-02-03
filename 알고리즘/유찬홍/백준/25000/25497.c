#include <stdio.h>

int main() {
    int n, r = 0, t[2] = {-1, -1};
    char s[200001];
    scanf("%d %s", &n, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'L' || s[i] == 'S') ++t[s[i] & 1];
        else {
            if (s[i] > 65 && t[s[i] & 1]-- < 0) break;
            r++;
        }
    }
    printf("%d", r);
}
