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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

const ll B = 31;

int t, n, m, l, r;
string s, p;

int rabin() {
    int occ = 0;
    ll hp = 0, hs = 0, E = 1;
    for (int i = 0; i < m; ++i) {
        hp = ((hp*B)%MOD + p[i])%MOD;
        hs = ((hs*B)%MOD + s[i])%MOD;
        E = (E*B)%MOD;
    }

    if (hs == hp) occ++;
    for (int i = m; i < n; ++i) {
        hs = ((hs*B)%MOD + s[i])%MOD;
        hs = (hs + (MOD - (s[i-m]*E)%MOD)%MOD)%MOD;
        if (hs == hp) occ++;
    }

    return occ;
}

int main () {
    getline(cin, s);
    getline(cin, p);
    scanf("%d", &t);

    n = s.size();
    l = 0;
    r = p.size();

    while (l < r) {
        m = (l+r+1)/2;
        int o = rabin();
        if (o < t) r = m-1;
        else l = m;
    }
    m = (l+r+1)/2;

    printf("%s\n", !m ? "IMPOSSIBLE" : p.substr(0, m).c_str());
    return 0;
}
