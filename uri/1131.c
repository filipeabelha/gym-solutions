#include <stdio.h>

int main() {
    int inter=0, gremio=0, emp=0, total=0;
    void calc() {
        void msg() {
            int opt;
            printf("Novo grenal (1-sim 2-nao)\n");
            scanf("%d", &opt);
            if (opt == 1) calc(); else if (opt != 2) msg(); else {
                printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n", total, inter, gremio, emp);
                if (inter > gremio) {
                    printf("Inter venceu mais\n");
                } else if (inter < gremio) {
                    printf("Gremio venceu mais\n");
                } else {
                    printf("Nao houve vencedor\n");
                };
            }
        };
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            inter++;
            total++;
            msg();
        } else if (x < y) {
            gremio++;
            total++;
            msg();
        } else if (x = y) {
            emp++;
            total++;
            msg();
        };
    };
    calc();
    return 0;
}
