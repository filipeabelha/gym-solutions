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
const int N = 1e3+5;

int n, m, s, t, a, b, ans;
int dist[N], distt[N];
set <pii> adj[N];
set <int> reach[N];
vi par[N];
priority_queue <pii> pq;

void dijkstra (int strt) {
    cl(dist, 63);
    dist[strt] = 0;
    pq.push(mp(0,strt));
    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (pii x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] == dist[u] + w) par[v].pb(u);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
                par[v].clear();
                par[v].pb(u);
            }
        }
    }
}

void dijkstraa (int strt) {
    cl(distt, 63);
    distt[strt] = 0;
    pq.push(mp(0,strt));
    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (pii x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (distt[v] > distt[u] + w) {
                distt[v] = distt[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}

int main () {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].insert({b, 1});
        adj[b].insert({a, 1});
    }
    dijkstra(s);
    dijkstraa(t);
    for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) {
        if (adj[i].count({j, 1})) continue;
        if (adj[j].count({i, 1})) continue;
        if (dist[i] + distt[j] + 1 < dist[t]) continue;
        if (dist[j] + distt[i] + 1 < dist[t]) continue;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
