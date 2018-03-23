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
const int N = 1e4+5;

int n, a, b, cnt, vis[N], inc[N];
vi adj[N];
queue <int> q;

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(vis, 0);
        cl(inc, 0);

        for (int i = 0; i < n-1; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
            inc[a]++;
            inc[b]++;
        }

        for (int i = 1; i <= n; ++i) if (inc[i] <= 1) q.push(i);

        printf("Teste %d\n", cnt);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (q.empty()) printf("%d\n\n", u);
            for (int v : adj[u])
                if (inc[v] > 1 and --inc[v] <= 1)
                    q.push(v);
        }
    }
    return 0;
}
