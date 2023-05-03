#include <stdio.h>

int main() {
    int w, h, arr[101][101];
    scanf("%d %d ", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 99) arr[i][j] = 0;
            else arr[i][j] = -1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (arr[i][j] > -1 && arr[i][j + 1] == -1) arr[i][j + 1] = arr[i][j] + 1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
