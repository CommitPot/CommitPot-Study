#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct g {
    int n;
    char s[17];
} g;

g a[300];

int comp(const void *x, const void *y) {
    return strcmp(a[*(int *) x].s, a[*(int *) y].s);
}

int main() {

    int p, m, c[300][300], d[300] = {}, e = 0;
    scanf("%d %d", &p, &m);
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &a[i].n, a[i].s);
        int f = 1;
        for (int j = 0; j < e; j++) {
            if (a[c[j][0]].n + 10 >= a[i].n && a[c[j][0]].n - 10 <= a[i].n && d[j] < m) {
                c[j][d[j]++] = i;
                f = 0;
                break;
            }
        }
        if (f) {
            c[e][d[e]++] = i, e++;
        }
    }
    for (int i = 0; i < e; i++) {
        printf("%s\n", d[i] == m ? "Started!" : "Waiting!");
        qsort(c[i], d[i], sizeof(d[i]), comp);
        for (int j = 0; j < d[i]; j++) {
            printf("%d %s\n", a[c[i][j]].n, a[c[i][j]].s);
        }
    }
}
