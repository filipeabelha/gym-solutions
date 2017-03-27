#include <bits/stdc++.h>

int main () {
        double n1, n2, n3, n4;
        scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
        double media = (2*n1 + 3*n2 + 4*n3 + n4)/10;
        printf("Media: %.1lf\n", media);
        if (media >= 7.0)       printf("Aluno aprovado.\n");
        else if (media < 5.0)   printf("Aluno reprovado.\n");
        else {
                printf("Aluno em exame.\n");
                double ex;
                scanf("%lf", &ex);
                printf("Nota do exame: %.1lf\n", ex);
                media = (media + ex) / 2;
                if (media >= 5.0) printf("Aluno aprovado.\nMedia final: %.1lf\n", media);
                else              printf("Aluno reprovado.\nMedia final: %.1lf\n", media);
        };
        return 0;
}
