#include <stdio.h>
#include <math.h>

int main() {
    int i, h, can, alt[150];
    scanf("%d %d", &h, &can);
    for (i = 1; i <= can; i++) {
        if (i != can) scanf("%d ", &alt[i]);
        else scanf("%d", &alt[i]);
    }
    int counter = 1;
    for (i = 2; i <= can; i++) {
        if (abs(alt[i] - alt[i-1]) > h) counter = 0;
    }
    if (counter == 1) printf("YOU WIN\n"); else if (counter == 0) printf("GAME OVER\n");
    return 0;
}
