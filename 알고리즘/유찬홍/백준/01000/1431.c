#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c(const void *a, const void *b) {
    char *A = (char *) a;
    char *B = (char *) b;
    int c = strlen(A), d = strlen(B);
    if (c != d) return c - d;
    int e = 0, f = 0;
    for (int i = 0; i < c; i++) {
        if (A[i] < 65) e += A[i] - 48;
    }
    for (int i = 0; i < d; i++) {
        if (B[i] < 65) f += B[i] - 48;
    }
    if (e != f) return e - f;
    return strcmp(A, B);
}

int main() {
    int n;
    char s[50][51];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof (s[0]), c);
    for (int i = 0; i < n; i++) printf("%s\n", s[i]);
}
