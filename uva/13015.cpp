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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e3+5;

int a, b, e, p, cnt;
int vis[N];
vi adj[N], adjt[N];
int num[N], numt[N];
int ansa, ansb, anstb;

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = 1; cnt++;
    for (auto v : adj[u]) dfs(v);
}

void dfst (int u) {
    if (vis[u]) return;
    vis[u] = 1; cnt++;
    for (auto v : adjt[u]) dfst(v);
}

int main () {
    while (~scanf("%d%d%d%d", &a, &b, &e, &p)) {
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < N; i++) adjt[i].clear();
        ansa = ansb = anstb = 0;
        cl(num, 0);
        cl(numt, 0);

        for (int x, y, i = 0; i < p; i++) {
            scanf("%d%d", &x, &y);
            adj[x].pb(y);
            adjt[y].pb(x);
        }
        for (int i = 0; i < e; i++) {
            cl(vis, 0);
            cnt = 0;
            dfs(i);
            num[i] = e-cnt+1;
        }
        for (int i = 0; i < e; i++) {
            cl(vis, 0);
            cnt = 0;
            dfst(i);
            numt[i] = cnt;
        }
        for (int i = 0; i < e; i++) {
            if (a >= num[i]) ansa++;
            if (b >= num[i]) ansb++;
            if (b < numt[i]) anstb++;
        }
        printf("%d\n%d\n%d\n", ansa, ansb, anstb);
    }
    return 0;
}
