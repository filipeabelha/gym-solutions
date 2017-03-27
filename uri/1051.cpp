#include <bits/stdc++.h>

int main () {
        double sal;
        scanf("%lf", &sal);
        if (sal <= 2000.00) printf("Isento\n");
        else if (sal <= 3000.00) sal -= 2000.00, printf("R$ %.2f\n", 0.08 * sal);
        else if (sal <= 4500.00) sal -= 2000.00, printf("R$ %.2f\n", 0.08 * 1000.00 + 0.18 * (sal - 1000.00));
        else                     sal -= 2000.00, printf("R$ %.2f\n", 0.08 * 1000.00 + 0.18 * 1500.00 + 0.28 * (sal - 2500.00));
        return 0;
}
