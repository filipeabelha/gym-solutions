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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int n, m, x, y, ans[N][N];
int memo[N][N][30][30][2];
char c;
vector <pair <int, char> > adj[N];

int go (int z, int na, int nb, char ca, char cb) {
    if (memo[na][nb][ca-'a'][cb-'a'][z] != -1) return memo[na][nb][ca-'a'][cb-'a'][z];

    if (z == 0) {
        for (auto v : adj[na]) if (v.nd >= cb) {
            if (go(1, v.st, nb, v.nd, cb)) return memo[na][nb][ca-'a'][cb-'a'][z] = 1;
        }
        return memo[na][nb][ca-'a'][cb-'a'][z] = 0;
    } else {
        for (auto v : adj[nb]) if (v.nd >= ca)
            if (!go(0, na, v.st, ca, v.nd)) return memo[na][nb][ca-'a'][cb-'a'][z] = 0;
        return memo[na][nb][ca-'a'][cb-'a'][z] = 1;
    }
}

int main () {
    cl(memo, -1);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf(" %d %d %c", &x, &y, &c);
        adj[x].pb(mp(y, c));
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        ans[i][j] = go(0, i, j, 'a'-1, 'a'-1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%c", ans[i][j] ? 'A' : 'B');
        printf("\n");
    }
    return 0;
}
