#include <bits/stdc++.h>

int main () {
        float a, b, c;
        scanf("%f%f%f", &a, &b, &c);
        float triangulo = a*c/2;
        float circulo = 3.14159 * c * c;
        float trapezio = (a+b)*c/2;
        float quadrado = b * b;
        float retangulo = a * b;
        printf("TRIANGULO: %.3f\nCIRCULO: %.3f\nTRAPEZIO: %.3f\nQUADRADO: %.3f\nRETANGULO: %.3f\n", triangulo, circulo, trapezio, quadrado, retangulo);
        return 0;
}
