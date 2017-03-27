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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

int dist[N];
vector <pii> adj[N];
priority_queue <pii> pq;
int n, e, tt, m, a, b, t, ans;

int main () {
    scanf("%d%d%d%d", &n, &e, &tt, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        adj[b-1].pb(mp(a-1,t));
    }
    memset(dist, 63, sizeof(dist));
    dist[e-1] = 0;
    pq.push(mp(0,e-1));
    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (pii x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                //printf("new dist[%d] = %d\n", v, dist[v]);
                pq.push(mp(-dist[v],v));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        //printf("dist[%d] = %d\n", i, dist[i]);
        if (dist[i] <= tt) ans++;
    }
    printf("%d\n", ans);

    return 0;
}
