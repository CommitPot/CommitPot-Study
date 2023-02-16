#include <stdio.h>

int main() {

    int T = 0, H = 0, W = 0, N = 0;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int x, y;

        scanf("%d %d %d", &H, &W, &N);

        x = N % H;
        if (x == 0) x = H;

        y = N / H + 1;
        if (N % H == 0) y -= 1;

        printf("%d%02d\n", x, y);
    }
}
