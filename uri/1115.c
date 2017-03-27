#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0 && y > 0) {
        printf("primeiro\n");
        main();
    } else if (x < 0 && y > 0) {
        printf("segundo\n");
        main();
    } else if (x < 0 && y < 0) {
        printf("terceiro\n");
        main();
    } else if (x > 0 && y < 0) {
        printf("quarto\n");
        main();
    } else {
    }
    return 0;
}
