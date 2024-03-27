#include <stdio.h>

typedef struct e {
    int x, y;
} e;

int ccw(e i, e j, e k) {
    return (i.x * j.y + j.x * k.y + k.x * i.y) - (i.y * j.x + j.y * k.x + k.y * i.x);
}

int main() {
    e a[3];
    for (int i = 0; i < 3; i++) scanf("%d %d", &a[i].x, &a[i].y);
    int x = ccw(a[0], a[1], a[2]);
    printf("%d", x ? x > 0 ? 1 : -1 : 0);
}
