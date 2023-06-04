#include <stdio.h>

typedef struct element {
    int a, c;
} element;

element queue[1000000];

int main() {
    int f, s, g, u, d, fr = 0, re = 0, arr[1000001] = {0};
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    queue[++re].a = s;
    queue[re].c = 0;
    while (fr < re) {
        int a = queue[++fr].a;
        int c = queue[fr].c;
        if (a == g) {
            printf("%d", c);
            return 0;
        }
        if (a + u <= f && !arr[a + u]) {
            queue[++re].a = a + u;
            queue[re].c = c + 1;
            arr[a + u] = 1;
        }
        if (a - d > 0 && !arr[a - d]) {
            queue[++re].a = a - d;
            queue[re].c = c + 1;
            arr[a - d] = 1;
        }
    }
    printf("use the stairs");
}
