#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, vis[N], dist[N];
vi adj[N];

int main () {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cl(dist, 63);
    queue <pii> q;
    vis[1] = 1;
    dist[1] = 0;
    q.push({1, 0});

    while (q.size()) {
        int v = q.front().st;
        int d = q.front().nd;
        q.pop();

        for (auto u : adj[v]) if (!vis[u]) {
            vis[u] = 1;
            dist[u] = d+1;
            q.push({u, dist[u]});
        }
    }

    printf("%d\n", dist[n]-1);


    return 0;
}
