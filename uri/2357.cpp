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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

int par[N], n, m, a, b, ok;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

int main () {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0 ; i < N; i++) par[i] = i;
        ok = 1;
        while (m--) {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) ok = 0;
            else unite(a, b);
        }
        printf("%s\n", ok ? "Seguro" : "Inseguro");
    }
    return 0;
}
