#include <stdio.h>

int main() {
    char name; double fix, vend, x;
    scanf("%s%lf%lf", &name, &fix, &vend);
    x = fix + 0.15*vend;
    printf("TOTAL = R$ %.2f\n", x);
    return 0;
}
