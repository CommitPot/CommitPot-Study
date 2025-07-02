#include <stdio.h>

int main() {
    int t, n;
    char s[101];
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %s", &n, s);
        for (int j = 0; s[j]; j++) {
            if (s[j] == 'c') n++;
            else n--;
        }
        printf("Data Set %d:\n%d\n\n", i, n);
    }
}
