#include <stdio.h>

int main() {
    int s = 2002, x;
    scanf("%d", &x);
    if (x != 2002) {
        printf("Senha Invalida\n");
        main();
    } else {
        printf("Acesso Permitido\n");
    };
    return 0;
}
