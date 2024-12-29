#include <stdio.h>

typedef struct element {
    long long int v, pre;
} element;
element arr[1000000];

void make_one(long long int n) {
    arr[1].v = arr[1].pre = 0;
    arr[2].v = arr[2].pre = 1;
    arr[3].v = arr[3].pre = 1;
    for (int i = 4; i <= n; i++) {
        if (i % 6 == 0) {
            if (arr[i / 3].v < arr[i / 2].v) {
                arr[i].v = arr[i / 3].v + 1;
                arr[i].pre = i / 3;
            } else {
                arr[i].v = arr[i / 2].v + 1;
                arr[i].pre = i / 2;
            }
        } else if (i % 3 == 0) {
            if (arr[i / 3].v < arr[i - 1].v) {
                arr[i].v = arr[i / 3].v + 1;
                arr[i].pre = i / 3;
            } else {
                arr[i].v = arr[i - 1].v + 1;
                arr[i].pre = i - 1;
            }
        } else if (i % 2 == 0) {
            if (arr[i / 2].v < arr[i - 1].v) {
                arr[i].v = arr[i / 2].v + 1;
                arr[i].pre = i / 2;
            } else {
                arr[i].v = arr[i - 1].v + 1;
                arr[i].pre = i - 1;
            }
        } else {
            arr[i].v = arr[i - 1].v + 1;
            arr[i].pre = i - 1;
        }
    }
}

int main() {
    long long int n, j;
    scanf("%lld", &n);
    make_one(n);
    printf("%lld\n%lld ", arr[n].v, n);
    j = arr[n].pre;
    while (j != 0) {
        printf("%lld ", j);
        j = arr[j].pre;
    }
    return 0;
}
