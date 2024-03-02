#include <stdio.h>

int main() {
    int n, m, a, b = 0, arr[101][101];
    scanf("%d %d", &n, &m);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            if (a != arr[i][j]) b = 1;
        }
    }
    if (b)
        printf("|>___/|     /}\n"
               "| O O |    / }\n"
               "( =0= )\"\"\"\"  \\\n"
               "| ^  ____    |\n"
               "|_|_/    ||__|");
    else
        printf("|>___/|        /}\n"
               "| O < |       / }\n"
               "(==0==)------/ }\n"
               "| ^  _____    |\n"
               "|_|_/     ||__|");
}
