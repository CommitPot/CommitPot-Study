#include <stdio.h>

int main() {
    int n, k;
    char s[1000001];
    scanf("%d %d %s", &n, &k, s);
    for (int i = 0; i < k - 1; i++) s[n + i] = s[(n - k) % 2 ? i : k - i - 2];
    s[n + k - 1] = 0;
    printf("%s", &s[k - 1]);
}
