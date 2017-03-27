#include <stdio.h>

int main() {
    int i, n, c = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("%d %d %d PUM\n", c, c+1, c+2);
        c = c+4;
    }
    return 0;
}
