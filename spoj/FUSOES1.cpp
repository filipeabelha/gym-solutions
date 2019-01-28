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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, a, b;
char c;

int par[N], sz[N];

int find (int x) { return par[x] == x ? x : par[x] = find(par[x]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'C') printf("%c\n", find(a) == find(b) ? 'S' : 'N');
        else unite(a, b);
    }
    return 0;
}
