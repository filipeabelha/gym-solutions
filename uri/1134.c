#include <stdio.h>

int main() {
    int a=0, g=0, d=0, x;
    void exec() {
        scanf("%d", &x);
        if (x == 1) {a++; exec();} else if (x == 2) {g++; exec();} else if (x == 3) {d++; exec();} else if (x == 4) {
            printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
        } else exec();
    };
    exec();
    return 0;
}
