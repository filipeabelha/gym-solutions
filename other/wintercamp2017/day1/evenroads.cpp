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
const int N = 1e4+5;

vector <pii> adj[N];
int dist[N][2];
int n, m;
priority_queue <piii> pq;

void dijkstra () {
    cl(dist, 63);
    dist[1][0] = 0;
    pq.push(mp(0, mp(1, 0)));
    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd.st;
        int m = pq.top().nd.nd;
        pq.pop();
        if (dist[u][m] < ud) continue;
        for (pii p : adj[u]) {
            int v = p.nd;
            int w = p.st;
            if (dist[v][1-m] > dist[u][m] + w) {
                dist[v][1-m] = dist[u][m] + w;
                pq.push(mp(-dist[v][1-m], mp(v, 1-m)));
            }
        }
    }
    printf("%d\n", dist[n][0] == INF ? -1 : dist[n][0]);
}

int main () {
    scanf("%d%d", &n, &m);
    for (int a, b, w, i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].pb(mp(w, b));
        adj[b].pb(mp(w, a));
    }
    dijkstra();
    return 0;
}
