#include <stdio.h>

int main() {
    int cod1, cod2, qtt1, qtt2; float prc1, prc2, x;
    scanf(" %d %d %f", &cod1, &qtt1, &prc1);
    scanf(" %d %d %f", &cod2, &qtt2, &prc2);
    x = qtt1*prc1 + qtt2*prc2;
    printf("VALOR A PAGAR: R$ %.2f\n", x);
    return 0;
}
