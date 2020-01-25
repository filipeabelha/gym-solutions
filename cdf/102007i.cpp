#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5+100;

struct edge {ll v, c, f;};

ll src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<ll> g[N];

void add_edge (ll u, ll v, ll c) {
    ll k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue<ll> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(ll i : g[u]) {
            ll v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

ll dfs (ll u, ll flow) {
    if (!flow or u == snk) return flow;
    for (ll &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        ll v = dir.v;
        if (h[v] != h[u] + 1) continue;
        ll inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (ll inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

ll n, m, s;
ll a, b, w;
ll x[N];
ll dist[N][15], cap[N], sum;
vector <pair <ll, ll> > adj[N], sh;

priority_queue <pair <ll, ll> > pq;

bool ok (ll t) {
    src = 0;
    snk = N-1;

    memset(h, 0, sizeof h);
    memset(ptr, 0, sizeof ptr);
    memset(cap, 0, sizeof cap);
    edgs.clear();
    for (ll i = 0; i < N; i++) g[i].clear();

    for (ll i = 0; i < sh.size(); i++) {
        ll s = sh[i].st;
        ll c = sh[i].nd;
        add_edge(1e5+5+i, snk, c);
    }

    for (ll v = 1; v <= n; v++) {
        ll u = 0;
        for (ll i = 0; i < sh.size(); i++) {
            ll s = sh[i].st;
            ll c = sh[i].nd;
            if (dist[v][i] <= t) {
                u |= (1 << i);
            }
        }

        cap[u] += x[v];
    }

    for (ll u = 1; u < N; u++) if (cap[u]) {
        add_edge(src, u+5, cap[u]);
        for (ll j = 0; j < 15; j++)
            if ((1 << j)&u) add_edge(u+5, 1e5+5+j, INF);
    }

    ll f = dinic();
    return (f == sum);
}

int main () {
    scanf("%lld%lld%lld", &n, &m, &s);
    for (ll i = 1; i <= n; i++) scanf("%lld", &x[i]), sum += x[i];
    while (m--) {
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    while (s--) {
        scanf("%lld%lld", &a, &b);
        sh.pb({a, b});
    }

    memset(dist, 63, sizeof dist);
    for (ll i = 0; i < sh.size(); i++) {
        ll s = sh[i].st;
        ll c = sh[i].nd;
        dist[s][i] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            ll ud = -pq.top().st;
            ll u = pq.top().nd; pq.pop();
            if (dist[u][i] < ud) continue;
            for (auto x : adj[u]) {
                ll v = x.st;
                ll w = x.nd;
                if (dist[v][i] > dist[u][i] + w) {
                    dist[v][i] = dist[u][i] + w;
                    pq.push({-dist[v][i], v});
                }
            }
        }
    }

    ll l = 0, m, r = INF;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else r = m;
    }

    printf("%lld\n", l);

    return 0;

}
