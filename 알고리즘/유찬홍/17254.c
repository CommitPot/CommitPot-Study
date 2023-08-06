#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int a, b;
    char c;
} e;

int comp(const void *a, const void *b) {
    e c = *(e *) a;
    e d = *(e *) b;
    if (c.b > d.b) return 1;
    else if (c.b < d.b) return -1;
    else {
        if (c.a > d.a) return 1;
        else return -1;
    }
}

int main() {
    int a, b;
    e arr[1000];
    scanf("%d %d", &a, &b);
    for (int i = 0; i < b; i++) scanf("%d %d %c", &arr[i].a, &arr[i].b, &arr[i].c);
    qsort(arr, b, sizeof(arr[0]), comp);
    for (int i = 0; i < b; i++) printf("%c", arr[i].c);
}
