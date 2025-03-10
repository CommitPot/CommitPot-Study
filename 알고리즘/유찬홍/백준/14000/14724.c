#include <stdio.h>

int main() {
    int n, k, r = 0;
    char *s[] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
    scanf("%d", &n);
    for (int i = 0, j; i < n * 9; i++) {
        scanf("%d", &j);
        if (r < j) {
            r = j;
            k = i / n;
        }
    }
    printf("%s", s[k]);
}
