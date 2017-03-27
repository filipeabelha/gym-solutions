#include <bits/stdc++.h>
using namespace std;

int n;
char ref1, ref2, num1, num2, chr, fem, masc;

int main () {
    for (int i = 1; 1; i++) {
        if (scanf("%c", &ref1) == EOF) break;
        if (i != 1) printf("\n");
        scanf("%c", &ref2);
        scanf("%c", &chr);
        fem = 0, masc = 0;
        while (1) {
            scanf("%c", &num1);
            scanf("%c", &num2);
            scanf("%c", &chr);
            scanf("%c", &chr);
            if (num1 == ref1 and num2 == ref2) {
                if (chr == 'M') masc++;
                if (chr == 'F') fem++;
            }
            scanf("%c", &chr);
            if (chr == 10) break;
        }
        printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n", i, masc+fem, fem, masc);
    }
    return 0;
}
