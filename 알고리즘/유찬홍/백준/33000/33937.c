#include <stdio.h>
#include <string.h>

int main() {
    int l = 0;
    char a[101], b[101];
    scanf("%s %s", a, b);
    while (a[l] != 'a' && a[l] != 'e' && a[l] != 'i' && a[l] != 'o' && a[l] != 'u' && a[l]) l++;
    while (a[l] == 'a' || a[l] == 'e' || a[l] == 'i' || a[l] == 'o' || a[l] == 'u') l++;
    if (l == strlen(a)) {
        printf("no such exercise");
        return 0;
    }
    a[l] = 0;
    l = 0;
    while (b[l] != 'a' && b[l] != 'e' && b[l] != 'i' && b[l] != 'o' && b[l] != 'u' && b[l]) l++;
    while (b[l] == 'a' || b[l] == 'e' || b[l] == 'i' || b[l] == 'o' || b[l] == 'u') l++;
    if (l == strlen(b)) {
        printf("no such exercise");
        return 0;
    }
    b[l] = 0;
    strcat(a, b);
    printf("%s", a);
}
