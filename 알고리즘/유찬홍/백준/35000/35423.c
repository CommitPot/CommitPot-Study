#include <stdio.h>

int main() {
    int a[2] = {};
    char s[1000001];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        a[0] += s[i] == 'S';
        a[1] += s[i] == 'L';
    }
    while (a[0]--) printf("SciCom");
    while (a[1]--) printf("Love");
}
