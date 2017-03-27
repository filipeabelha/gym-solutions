#include <stdio.h>

int main() {
    int i, m, n;
    scanf("%d %d", &m, &n);
    for (i = 1; i <= n; i++) {
        if (i % m != 0) printf("%d ", i); else printf("%d\n", i);
    }
    if (n % m != 0) printf("\n");
    return 0;
}
