#include <stdio.h>

int main() {
    int p, w, r = 0;
    char s[1001], *a = "22233344455566677778889999", *b = "12312312312312312341231234";
    scanf("%d %d %[^\n]", &p, &w, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') r += p;
        else {
            r += (b[s[i] - 65] - 48) * p;
            if (i && a[s[i] - 65] == a[s[i - 1] - 65]) r += w;
        }
    }
    printf("%d", r);
}
