#include <stdio.h>

int main() {
    int v;
    scanf("%d", &v);
    printf("%d\n", v);

    int cem = v/100;
    v = v - cem*100;
    printf("%d nota(s) de R$ 100,00\n", cem);

    int cinquenta = v/50;
    v = v - cinquenta*50;
    printf("%d nota(s) de R$ 50,00\n", cinquenta);

    int vinte = v/20;
    v = v - vinte*20;
    printf("%d nota(s) de R$ 20,00\n", vinte);

    int dez = v/10;
    v = v - dez*10;
    printf("%d nota(s) de R$ 10,00\n", dez);

    int cinco = v/5;
    v = v - cinco*5;
    printf("%d nota(s) de R$ 5,00\n", cinco);

    int dois = v/2;
    v = v - dois*2;
    printf("%d nota(s) de R$ 2,00\n", dois);

    int um = v;
    printf("%d nota(s) de R$ 1,00\n", um);
    return 0;
}
