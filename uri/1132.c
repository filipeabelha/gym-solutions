#include <stdio.h>

int main() {
    int x, y, i, sum = 0;
    scanf("%d%d", &x, &y);
    if (x > y) {
        int aux = x;
        x = y;
        y = aux;
    };
    for (i = x; i <= y; i++) {
        if (i % 13 != 0) sum = sum + i;
    }
    printf("%d\n", sum);
    return 0;
}
