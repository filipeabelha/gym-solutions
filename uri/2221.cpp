#include <bits/stdc++.h>
using namespace std;

int n, k, a1, d1, l1, a2, d2, l2;
double g1, g2;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        scanf("%d%d%d%d%d%d", &a1, &d1, &l1, &a2, &d2, &l2);
        g1 = (a1 + d1)/2;
        if (l1 % 2 == 0) g1 += k;
        g2 = (a2 + d2)/2;
        if (l2 % 2 == 0) g2 += k;
        if (g1 > g2) printf("Dabriel\n");
        else if (g2 > g1) printf("Guarte\n");
        else printf("Empate\n");
    }
    return 0;
}
