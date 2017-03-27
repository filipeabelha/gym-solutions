#include <stdio.h>

int main() {
    int x, y, i;
    scanf("%d %d", &x, &y);
    if (y < x) {
        int aux = x;
        x = y;
        y = aux;
    };
    if (x > 0 && y > 0) {
        int sum = 0;
        for (i = x; i <= y; i++) {
            printf("%d ", i);
            sum = sum + i;
        };
        printf("Sum=%d\n", sum);
        main();
    };
    return 0;
}
