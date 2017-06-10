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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

const int N = 1e4+ 10; // Maximum number of nodes
int dist[N][2];
vector <pii> adj[N];
priority_queue <piii> pq;
int n1, n2, s, strt, edges;

void dijkstra () {
    for (int i = 0; i < edges; i++) {
        scanf("%d%d%d", &n1, &n2, &s);
        adj[n1].pb(mp(n2,s));
        adj[n2].pb(mp(n1,s));
    }
    cl(dist, 63);
    dist[strt][0] = 0;
    pq.push(mp(0, mp(0,strt)));
    while (!pq.empty()) {
        int ud = -pq.top().nd.st;
        int u = pq.top().nd.nd;
        int mode = pq.top().st; pq.pop();
        if (dist[u][mode] < ud) continue;
        for (pii x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v][1-mode] > dist[u][mode] + w) {
                dist[v][1-mode] = dist[u][mode] + w;
                pq.push(mp(1-mode, mp(-dist[v][1-mode],v)));
            }
        }
    }
}

int main () {
    int targ;
    scanf("%d%d", &targ, &edges);
    strt = 1;
    dijkstra();
    printf("%d\n", dist[targ][0] == INF ? -1 : dist[targ][0]);
    return 0;
}
