#include <stdio.h>

int main() {
    int num, hrs; float vlu, x;
    scanf("%d%d%f", &num, &hrs, &vlu);
    printf("NUMBER = %d\n", num);
    x = (hrs*vlu);
    printf("SALARY = U$ %.2f\n", x);
    return 0;
}
