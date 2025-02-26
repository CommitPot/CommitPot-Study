#include <stdio.h>
#include <string.h>

int main() {
    int r = 0;
    char a[100001], b[11];
    scanf("%s %s", a, b);
    int l = strlen(b);
    for (int i = 0; a[i + l - 1]; i++) {
        char t = a[i + l];
        a[i + l] = 0;
        if (strstr(&a[i], b)) r++;
        a[i + l] = t;
    }
    printf("%d", r);
}
