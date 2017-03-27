#include <stdio.h>
#include <math.h>

int main() {
    float n, s=0;
    int c = 0;
    void calc() {
        scanf("%f", &n);
        if (n < 0 || n > 10) {
            printf("nota invalida\n");
            calc();
        } else if (c < 1) {
            c++;
            s = s + n;
            calc();
        } else if (c == 1) {
            s = s + n;
            printf("media = %.2f\n", s/2);
        };
    };
    calc();
    return 0;
}
