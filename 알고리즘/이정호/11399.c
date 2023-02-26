#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int *a1 = (int *) a, *b1 = (int *) b;
    if (*a1 > *b1) return 1;
    else if (*a1 < *b1) return -1;
    return 0;
}

int main() {
    int n = 0, count = 0, time = 0;
    int p[1001] = {0};

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }

    qsort(p, n, 4, comp);

    for(int k=0; k<n; k++) {
        count += p[k];
        time += count;
    }

    printf("%d\n", time);
    return 0;
}
