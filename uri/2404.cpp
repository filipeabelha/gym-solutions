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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2+10;

int n, m, a, b, w, par[N];

int find (int k) {
    return (par[k] == k ? k : par[k] = find(par[k]));
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

vector <piii> v;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        v.pb(mp(w, mp(a, b)));
    }
    for (int i = 0; i < N; i++) par[i] = i;
    int cost = 0;
    sort(v.begin(), v.end());
    for (auto p : v) {
        int a = p.nd.st;
        int b = p.nd.nd;
        int w = p.st;
        if (find(a) == find(b)) continue;
        unite(a, b);
        cost += w;
    }
    printf("%d\n", cost);
    return 0;
}
