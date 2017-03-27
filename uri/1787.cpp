#include <bits/stdc++.h>

using namespace std;
set <int> pot;

int main () {
    int val = 2;
    for (int i = 2; i <= 31; i++)
        pot.insert(val), val *= 2;
    int n;
    while (scanf("%d", &n)) {
        int U = 0, R = 0, I = 0;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            int uu = 0, rr = 0, ii = 0;
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if ((int) pot.count(x)) uu++;
            if ((int) pot.count(y)) rr++;
            if ((int) pot.count(z)) ii++;
            if (uu and x>y and x>z) uu++;
            if (rr and y>x and y>z) rr++;
            if (ii and z>x and z>y) ii++;
            U += uu;
            R += rr;
            I += ii;
        }
        if (U > R and U > I) printf("Uilton\n");
        else if (R > U and R > I) printf("Rita\n");
        else if (I > U and I > R) printf("Ingred\n");
        else printf("URI\n");
    }
    return 0;
}

