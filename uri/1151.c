#include <stdio.h>

int main() {
    int x, a = 0, b = 1, i;
    scanf("%d", &x);
    for (i = 0; i < x; i++) {
        if (i == 0) printf("0 ");
        else if (i == 1) printf("1 ");
        else {
            if (i != x - 1) printf("%d ", a + b); else printf("%d", a + b);
            int aux = a;
            a = b;
            b = b + aux;
        }
    }
    printf("\n");
    return 0;
}
