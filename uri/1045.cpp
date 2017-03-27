#include <bits/stdc++.h>

int main () {
        double l[3];
        scanf("%lf %lf %lf", &l[0], &l[1], &l[2]);
        
        double a = -1;
        double b = -1;
        double c;
        int ia;
        int ib;
        for (int i = 0; i < 3; i++) if (l[i] > a)               a = l[i], ia = i;
        for (int i = 0; i < 3; i++) if (i != ia and l[i] > b)   b = l[i], ib = i;
        for (int i = 0; i < 3; i++) if (i != ia and i != ib)    c = l[i];

        if (a >= b + c)         printf("NAO FORMA TRIANGULO\n"); else {
        if (a*a == b*b + c*c)   printf("TRIANGULO RETANGULO\n");
        if (a*a >  b*b + c*c)   printf("TRIANGULO OBTUSANGULO\n");
        if (a*a <  b*b + c*c)   printf("TRIANGULO ACUTANGULO\n");
        if (a == b and b == c)  printf("TRIANGULO EQUILATERO\n"); else if (a == b or b == c or a == c)  printf("TRIANGULO ISOSCELES\n");
        };

        return 0;
}
