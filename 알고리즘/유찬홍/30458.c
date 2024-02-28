#include <stdio.h>

int main() {
    int n, a[26] = {0};
    char s[200001];
    scanf("%d %s", &n, s);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        a[s[i] - 97]++;
        a[s[j] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}
