#include <stdio.h>
#include <math.h>

int func(int w, int x, int y, int r, int c, int rs) {
    if (!w) return rs;
    int m = w >> 1;
    int z = m * m;
    if (r < x + m && c < y + m) return func(m, x, y, r, c, rs);
    else if (r < x + m && c >= y + m) return func(m, x, y + m, r, c, rs + z);
    else if (r >= x + m && c < y + m) return func(m, x + m, y, r, c, rs + 2 * z);
    else return func(m, x + m, y + m, r, c, rs + 3 * z);
}

int main() {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", func((int) pow(2, n), 0, 0, r, c, 0));
}
