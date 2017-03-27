#include <stdio.h>

int main() {
    float s = 0, c = 0, x;
    void calc() {
        scanf("%f", &x);
        if (x >= 0) {
            s = s+x;
            c = c+1;
            calc();
        } else {
            printf("%.2f\n", s/c);
        }
    };
    calc();
    return 0;
}
