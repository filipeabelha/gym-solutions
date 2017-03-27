#include <stdio.h>

int main() {
    int n, i, t[2000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 0; i < n; i++) {
        if (t[i] % 2 == 0) printf("0\n"); else printf("1\n");
    }
    return 0;
}
