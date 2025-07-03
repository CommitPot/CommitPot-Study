#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a[3] = {1,};
    char s[51];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') swap(&a[0], &a[1]);
        else if (s[i] == 'B') swap(&a[1], &a[2]);
        else swap(&a[0], &a[2]);
    }
    printf("%d", a[0] ? 1 : a[1] ? 2 : 3);
}
