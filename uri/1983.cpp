#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    int matmax = 0;
    double notamax = 0;
    for (int i = 0; i < n; i++) {
        int mat;
        double nota;
        scanf("%d%lf", &mat, &nota);
        if (nota > notamax) notamax = nota, matmax = mat;
    }
    if (notamax >= 8) printf("%d\n", matmax); else printf("Minimum note not reached\n");
    return 0;
}
