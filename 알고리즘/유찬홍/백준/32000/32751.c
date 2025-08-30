#include <stdio.h>

int main() {
    int n, a[4], r = 1;
    char s[100001];
    scanf("%d %d %d %d %d %s", &n, &a[0], &a[1], &a[2], &a[3], &s);
    if (s[0] != 'a' || s[n - 1] != 'a') r = 0;
    a[s[0] - 97]--;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) r = 0;
        a[s[i] - 97]--;
        if (a[s[i] - 97] < 0) r = 0;
    }
    printf("%s", r ? "Yes" : "No");
}
