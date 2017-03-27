#include <stdio.h>

int main() {
    int cod, qtt;
    scanf("%d %d", &cod, &qtt);
    float prc[5] = {4.00, 4.50, 5.00, 2.00, 1.50};
    float total = prc[cod-1] * qtt;
    printf("Total: R$ %.2f\n", total);
    return 0;
}
