#include <bits/stdc++.h>
using namespace std;

int n, ts, tb, ta, s, b, a, x, y, z;
float ps, pb, pa;
string st;
char chr;

int main () {
    scanf("%d%c", &n, &chr);
    for (int i = 0; i < n; i++) {
        getline(cin, st);
        scanf("%d%c%d%c%d%c", &x, &chr, &y, &chr, &z, &chr);
        ts += x; tb += y; ta += z;
        scanf("%d%c%d%c%d%c", &x, &chr, &y, &chr, &z, &chr);
        s += x; b += y; a += z;
    }
    ps = (float) s*100/ts; pb = (float) b*100/tb; pa = (float) a*100/ta;
    printf("Pontos de Saque: %.2f %%.\n", ps);
    printf("Pontos de Bloqueio: %.2f %%.\n", pb);
    printf("Pontos de Ataque: %.2f %%.\n", pa);
    return 0;
}
