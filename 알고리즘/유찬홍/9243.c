#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[1001], b[1001];
    scanf("%d %s %s", &n, a, b);
    while (n--) {
        for (int i = 0; a[i]; i++) a[i] = a[i] - 48 ? 48 : 49;
    }
    printf("%s", strcmp(a, b) ? "Deletion failed" : "Deletion succeeded");
}
