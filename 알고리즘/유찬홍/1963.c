#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    int c;
    char s[5];
} element;

int main() {
    int t, arr[10000] = {0};
    char a[5], b[5];
    for (int i = 2; i <= 100; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 9999; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s %s", a, b);
        int f = 0, r = 0;
        int vis[10000] = {0};
        element queue[1500];
        strcpy(queue[++r].s, a);
        queue[r].c = 0;
        vis[atoi(a)] = 1;
        while (f < r) {
            char s[5];
            strcpy(s, queue[++f].s);
            int c = queue[f].c;
            if (!strcmp(s, b)) {
                printf("%d\n", c);
                break;
            }
            char sa[5];
            strcpy(sa, s);
            for (int j = 0; j < 4; j++) {
                for (char k = 48; k < 58; k++) {
                    s[j] = k;
                    int num = atoi(s);
                    if (num > 1000 && !arr[num] && !vis[num]) {
                        vis[num] = 1;
                        strcpy(queue[++r].s, s);
                        queue[r].c = c + 1;
                    }
                    s[j] = sa[j];
                }
            }
        }
    }
}
