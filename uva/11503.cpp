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
const int M = 50;

int par[N], sz[N];
map <string, int> id;
char s[M], t[M];
int tc, n, cnt;

int find (int x) { return par[x] == x ? x : x = find(par[x]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[b] > sz[a]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        cnt = 0;
        id.clear();

        scanf(" %d", &n);
        while (n--) {
            scanf(" %s %s", s, t);
            if (!id.count(s)) id[s] = ++cnt;
            if (!id.count(t)) id[t] = ++cnt;
            unite(id[s], id[t]);
            printf("%d\n", sz[find(id[s])]);
        }
    }
    return 0;
}
