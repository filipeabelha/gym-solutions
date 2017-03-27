#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x != y) {
        if (x > y) printf("Decrescente\n");
        if (y > x) printf("Crescente\n");
        main();
    };
    return 0;
}
