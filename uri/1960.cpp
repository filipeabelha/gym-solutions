#include <bits/stdc++.h>

int main () {

    int n;
    scanf("%d", &n);

    if      (n >= 900) printf("CM"),   n -= 900;
    else if (n >= 800) printf("DCCC"), n -= 800;
    else if (n >= 700) printf("DCC"),  n -= 700;
    else if (n >= 600) printf("DC"),   n -= 600;
    else if (n >= 500) printf("D"),    n -= 500;
    else if (n >= 400) printf("CD"),   n -= 400;
    else if (n >= 300) printf("CCC"),  n -= 300;
    else if (n >= 200) printf("CC"),   n -= 200;
    else if (n >= 100) printf("C"),    n -= 100;

    if      (n >= 90)  printf("XC"),   n -= 90;
    else if (n >= 80)  printf("LXXX"), n -= 80;
    else if (n >= 70)  printf("LXX"),  n -= 70;
    else if (n >= 60)  printf("LX"),   n -= 60;
    else if (n >= 50)  printf("L"),    n -= 50;
    else if (n >= 40)  printf("XL"),   n -= 40;
    else if (n >= 30)  printf("XXX"),  n -= 30;
    else if (n >= 20)  printf("XX"),   n -= 20;
    else if (n >= 10)  printf("X"),    n -= 10;

    if      (n == 9)  printf("IX");
    else if (n == 8)  printf("VIII");
    else if (n == 7)  printf("VII");
    else if (n == 6)  printf("VI");
    else if (n == 5)  printf("V");
    else if (n == 4)  printf("IV");
    else if (n == 3)  printf("III");
    else if (n == 2)  printf("II");
    else if (n == 1)  printf("I");

    printf("\n");

    return 0;
}
