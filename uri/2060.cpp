#include <bits/stdc++.h>

int n, k, m2, m3, m4, m5;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k % 2 == 0) m2++;
        if (k % 3 == 0) m3++;
        if (k % 4 == 0) m4++;
        if (k % 5 == 0) m5++;
    }
    printf("%d Multiplo(s) de 2\n", m2);
    printf("%d Multiplo(s) de 3\n", m3);
    printf("%d Multiplo(s) de 4\n", m4);
    printf("%d Multiplo(s) de 5\n", m5);
    return 0;
}
