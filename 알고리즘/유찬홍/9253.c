#include <string.h>

int main() {
    char a[200001], b[200001], c[200001];
    scanf("%s %s %s", a, b, c);
    printf("%s", strstr(a, c) && strstr(b, c) ? "YES" : "NO");
}
