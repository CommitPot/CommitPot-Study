#include <stdio.h>

int main() {
    int n, r = 0, a[1000001], s[1000001] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        if (s[a[i] + 1]) s[a[i] + 1]--;
        else r++;
        s[a[i]]++;
    }
    printf("%d", r);
}
