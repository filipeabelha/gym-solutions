#include <stdio.h>

int main() {
    int a, m, d;
    scanf("%d", &d);

    a = d/365;
    d = d - a*365;

    m = d/30;
    d = d - m*30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", a, m, d);
    return 0;
}
