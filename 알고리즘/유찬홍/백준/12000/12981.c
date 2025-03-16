#include <stdio.h>

int main() {
    int r, g, b, k = 0;
    scanf("%d %d %d", &r, &g, &b);
    k += r / 3 + g / 3 + b / 3;
    r %= 3;
    g %= 3;
    b %= 3;
    while (r && g && b) k++, r--, g--, b--;
    if (r == g && g == b) {
        k += r;
    } else {
        if (!r) {
            if (!g || !b) k++;
            else k += g > b ? g : b;
        }
        else if (!g) {
            if (!r || !b) k++;
            else k += r > b ? r : b;
        }
        else if (!b) {
            if (!r || !g) k++;
            else k += r > g ? r : g;
        }
    }
    printf("%d", k);
}
