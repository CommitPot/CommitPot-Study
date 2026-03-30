#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n, r = 0;
    char s[26], a[101];
    scanf("%d %s", &n, s);
    while (n--) {
        scanf("%s", a);
        int len = strlen(a);
        r += [&] {
            for (int j = 0; a[j]; j++) {
                if (a[j] == s[0]) {
                    for (int k = j + 1; a[k]; k++) {
                        if (a[k] == s[1]) {
                            int p = 1;
                            for (int l = 2; l < s[l]; l++) {
                                if (j + (k - j) * l > len || a[j + (k - j) * l] != s[l]) p = 0;
                            }
                            if (p) return 1;
                        }
                    }
                }
            }
            return 0;
        }();
    }
    printf("%d", r);
}
