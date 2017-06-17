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

int l[N], r[N], tc, n, strt, x;
vi pre, inf, pos;

void add (int who, int to) {
    if (who < to and l[to] == -1) l[to] = who;
    if (who > to and r[to] == -1) r[to] = who;
    if (who < to and l[to] >= +0) add(who, l[to]);
    if (who > to and r[to] >= +0) add(who, r[to]);
}

void dfs (int x) {
    pre.pb(x);
    if (l[x] >= 0) dfs(l[x]);
    inf.pb(x);
    if (r[x] >= 0) dfs(r[x]);
    pos.pb(x);
}

int main () {
    scanf("%d", &tc); for (int t = 1; t <= tc; t++) {
        cl(l, -1); cl(r, -1);
        pre.clear(); inf.clear(); pos.clear();
        scanf("%d%d", &n, &strt);
        for (int i = 1; i < n; i++) {
            scanf("%d", &x);
            add(x, strt);
        }
        dfs(strt);
        printf("Case %d:\n", t);
        printf("Pre.: ");
        for (int i = 0; i < n; i++)
            printf("%d%s", pre[i], i < n-1 ? " " : "\n");
        printf("In..: ");
        for (int i = 0; i < n; i++)
            printf("%d%s", inf[i], i < n-1 ? " " : "\n");
        printf("Post: ");
        for (int i = 0; i < n; i++)
            printf("%d%s", pos[i], i < n-1 ? " " : "\n");
        printf("\n");
    }
    return 0;
}

