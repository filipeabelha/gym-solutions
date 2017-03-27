#include <stdio.h>

int main() {
    int i, x;
    void calc() {
        scanf("%d", &x);
        if (x != 0) {
            for (i = 1; i <= x; i++) {
                if (i != x) printf("%d ", i); else printf("%d\n", i);
            }
            calc();
        }
    };
    calc();
    return 0;
}
