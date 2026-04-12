#include <stdio.h>

int main() {
    int t, r;
    char a[100001], b[100001];
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", a, b);
        r = 0;
        for (int i = 0, j; a[i]; i++) {
            if (a[i] == b[i]) continue;
            for (j = i + 1; b[j] != a[i]; j++) {}
            r += j - i;
            b[i] = b[i] == 97 ? 98 : 97;
            b[j] = b[j] == 97 ? 98 : 97;
        }
        printf("%d\n", r);
    }
}
