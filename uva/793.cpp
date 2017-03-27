#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n, pc, c1, c2, rht, wro;
char chr;
string s;
vector <int> par;

int findPar (int i) {
    if (par[i] == i) return i;
    return par[i] = findPar(par[i]);
}

void insPar (int x, int y) {
    if (x > y) {
        insPar(y, x);
        return;
    }
    int par1 = findPar(x);
    int par2 = findPar(y);
    (par1 < par2) ? par[par2] = par1 : par[par1] = par2;
}

int main () {
    scanf("%d%c", &n, &chr);
    while (n--) {
        rht = 0; wro = 0;
        scanf("%d%c", &pc, &chr);
        par.clear();
        for (int i = 0; i <= pc; i++) par.pb(i);
        while (1) {
            getline(cin, s);
            if (s.size() == 0) break;
            sscanf(s.c_str(), "%c%d%d", &chr, &c1, &c2);
            if (chr == 'c')
                insPar(c1, c2);
            else if (chr == 'q') {
                if (findPar(c1) == findPar(c2)) rht++;
                else wro++;
            }
        }
        printf("%d,%d\n", rht, wro);
        if (n) printf("\n");
    }
    return 0;
}
