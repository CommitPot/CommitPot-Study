#include <stdio.h>
#include <string.h>

int main() {
    char s[121], r[5001], p[121], b[121];
    scanf("%[^\n]", s);
    for (int i = 0, j = 0, k = 0; s[i]; i++) {
        if (s[i] == 32) {
            strcat(r, p);
            k += j;
            int l = i + 1, m = 0;
            for (; s[l] != '[' && s[l] != ']' && s[l] != '*' && s[l] != '&' && s[l] != ',' && s[l] != ';'; l++)
                b[m++] = s[l];
            int o = l;
            while (s[o] != ',' && s[o] != ';') o++;
            for (--o; o >= l; o--) r[k++] = s[o] == '[' ? ']' : s[o] == ']' ? '[' : s[o];
            r[k++] = 32;
            strcat(r, b);
            k += m;
            r[k++] = ';';
            r[k++] = '\n';
        }
        if (!j) {
            if (s[i] == 32) j = i;
            else p[k++] = s[i];
        }
    }
    printf("%s", r);
}
