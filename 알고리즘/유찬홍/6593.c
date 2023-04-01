#include <stdio.h>

typedef struct element {
    int x, y, z, c;
} element;
int l, r, c, fr = 0, re = 0;
char arr[31][31][31];
element queue[1000000];

int bfs(int i, int j, int k) {
    queue[++re].x = i;
    queue[re].y = j;
    queue[re].z = k;
    queue[re].c = 0;
    while (fr < re) {
        int x = queue[++fr].x;
        int y = queue[fr].y;
        int z = queue[fr].z;
        int count = queue[fr].c;
        if (arr[x][y][z] == 'E') return count;
        else if (arr[x][y][z] != '#') {
            arr[x][y][z] = '#';
            if (arr[x + 1][y][z] != '#' && x + 1 <= l) {
                queue[++re].x = x + 1;
                queue[re].y = y;
                queue[re].z = z;
                queue[re].c = count + 1;
            }
            if (arr[x - 1][y][z] != '#' && x - 1 > 0) {
                queue[++re].x = x - 1;
                queue[re].y = y;
                queue[re].z = z;
                queue[re].c = count + 1;
            }
            if (arr[x][y + 1][z] != '#' && y + 1 <= r) {
                queue[++re].x = x;
                queue[re].y = y + 1;
                queue[re].z = z;
                queue[re].c = count + 1;
            }
            if (arr[x][y - 1][z] != '#' && y - 1 > 0) {
                queue[++re].x = x;
                queue[re].y = y - 1;
                queue[re].z = z;
                queue[re].c = count + 1;
            }
            if (arr[x][y][z + 1] != '#' && z + 1 <= c) {
                queue[++re].x = x;
                queue[re].y = y;
                queue[re].z = z + 1;
                queue[re].c = count + 1;
            }
            if (arr[x][y][z - 1] != '#' && z - 1 > 0) {
                queue[++re].x = x;
                queue[re].y = y;
                queue[re].z = z - 1;
                queue[re].c = count + 1;
            }
        }
    }
    return -1;
}

int main() {
    while (1) {
        int d, e, f;
        scanf("%d %d %d", &l, &r, &c);
        if (!l) return 0;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                for (int k = 1; k <= c; k++) {
                    scanf(" %1c", &arr[i][j][k]);
                    if (arr[i][j][k] == 'S') d = i, e = j, f = k;
                }
            }
        }
        int a = bfs(d, e, f);
        fr = re = 0;
        if (a == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", a);
    }
}