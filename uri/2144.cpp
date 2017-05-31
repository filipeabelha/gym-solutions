#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

double u, v, r, m, mm;
int ok = 1, cnt = 0;

int main () {
    while (1) {
        scanf("%lf%lf%lf", &u, &v, &r);
        if (!u and !v and !r) break;
        m = (u+v)*(1+r/30)/2;
        mm += m; cnt++;
        if (m > 60)       printf("AQUI E BODYBUILDER!!\n");
        else if (m >= 40) printf("Ta saindo da jaula o monstro!\n");
        else if (m >= 14) printf("Bora, hora do show! BIIR!\n");
        else if (m >= 13) printf("E 13\n");
        else if (m >= 1)  printf("Nao vai da nao\n");
    }
    if (mm/cnt > 40) printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
    return 0;
}
