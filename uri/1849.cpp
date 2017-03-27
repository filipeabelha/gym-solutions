#include <bits/stdc++.h>
using namespace std;

int main () {
        int ld, cd, lv, cv;
        scanf("%d%d%d%d", &ld, &cd, &lv, &cv);
        if (ld > cd) {int aux = ld; ld = cd; cd = aux;}
        if (lv > cv) {int aux = lv; lv = cv; cv = aux;}
        int q = min (ld + lv, min(cd, cv));
        printf("%d\n", q*q);
        return 0;
}
