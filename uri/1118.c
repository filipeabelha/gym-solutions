#include <stdio.h>

int main() {
    void calcmaster() {
        float n, s=0;
        int c = 0;
        void msg() {
            int opt;
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &opt);
            if (opt == 1) calcmaster(); else if (opt != 2) msg();
        };
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
                msg();
            };
        };
        calc();
    };
    calcmaster();
    return 0;
}
