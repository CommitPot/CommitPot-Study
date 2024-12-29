#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
    return strcmp((char *) a, (char *) b);
}

char arr[16];
int l, c, vis[16] = {0};

void bt(char *arr1, int len, int a, int b) {
    if (len > 0) {
        if (arr1[len] < arr1[len - 1]) return;
    }
    if (len + 1 == l) {
        if (a >= 1 && b >= 2) {
            for (int i = 0; i <= len; i++) {
                printf("%c", arr1[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < c; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr1[++len] = arr[i];
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')a++;
            else b++;
            bt(arr1, len, a, b);
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')a--;
            else b--;
            len--;
            vis[i] = 0;
        }
    }
}

int main() {
    char arr1[16];
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++) {
        scanf(" %c", &arr[i]);
    }
    qsort(arr, c, 1, comp);
    bt(arr1, -1, 0, 0);
}
