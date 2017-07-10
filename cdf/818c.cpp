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

typedef long long lli;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<lli, lli> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int d, n, m;
int l, r, t, b;
int ll[N], rr[N], tt[N], bb[N];
int vert[N], hori[N];
int xa, ya, xb, yb;
set <int> x[N], y[N];
vector <pair <pii, pii> > sofas;

int main () {
    scanf("%d%d%d", &d, &n, &m);
    for (int i = 0; i < d; i++) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        x[xa].insert(i);
        x[xb].insert(i);
        y[ya].insert(i);
        y[yb].insert(i);
        sofas.pb(mp(mp(xa, xb), mp(ya, yb)));
        if (xa == xb) vert[i] = 1;
        if (ya == yb) hori[i] = 1;
    }
    set <int> sumx, sumy;
    for (int i = 0; i <= N-2; i++) {
        for (auto k : x[i]) sumx.insert(k);
        for (auto k : y[i]) sumy.insert(k);
        ll[i+1] = sumx.size();
        tt[i+1] = sumy.size();
    }
    sumx.clear(); sumy.clear();
    for (int i = N-1; i > 0; i--) {
        for (auto k : x[i]) sumx.insert(k);
        for (auto k : y[i]) sumy.insert(k);
        rr[i-1] = sumx.size();
        bb[i-1] = sumy.size();
    }
    scanf("%d%d%d%d", &l, &r, &t, &b);
    for (int i = 0; i < d; i++) {
        pii xx = sofas[i].st;
        pii yy = sofas[i].nd;
        int ok = 1;
        if (ll[max(xx.st, xx.nd)] - hori[i] != l) ok = 0;
        if (rr[min(xx.st, xx.nd)] - hori[i] != r) ok = 0;
        if (tt[max(yy.st, yy.nd)] - vert[i] != t) ok = 0;
        if (bb[min(yy.st, yy.nd)] - vert[i] != b) ok = 0;
        if (ok) return 0*printf("%d\n", i+1);
    }
    printf("-1\n");
    return 0;
}
