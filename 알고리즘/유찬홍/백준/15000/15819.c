#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c(const void *a, const void *b) {
    return strcmp((char *) a, (char *) b);
}

int main() {
    int n, m;
    char s[100][21];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    qsort(s, n, 21, c);
    printf("%s", s[--m]);
}
