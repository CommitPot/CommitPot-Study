#include <stdio.h>
#include <string.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        int r = 0;
        char s[21];
        scanf("%d", &n);
        while (n--) {
            int k;
            char z[21];
            scanf("%d %s", &k, z);
            if (r < k) r = k, strcpy(s, z);
        }
        printf("%s\n", s);
    }
}
