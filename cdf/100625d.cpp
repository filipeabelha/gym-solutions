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
const int N = 2e3+5;

ll tc;
ll n, m, t;
ll s, g, h;
ll a, b, w;
ll x;

ll dist[N], ok[N];
vector <pll> adj[N];
priority_queue <pll> pq;

int main () {
    scanf("%lld", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            dist[i] = LINF;
            ok[i] = 0;
            adj[i].clear();
        }

        scanf("%lld%lld%lld", &n, &m, &t);
        scanf("%lld%lld%lld", &s, &g, &h);
        while (m--) {
            scanf("%lld%lld%lld", &a, &b, &w);
            adj[a].pb({b, w});
            adj[b].pb({a, w});
        }

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            ll ud = -pq.top().st;
            ll u = pq.top().nd; pq.pop();
            if (dist[u] < ud) continue;
            for (auto x : adj[u]) {
                ll v = x.st;
                ll w = x.nd;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    ok[v] = ok[u];
                    if (v == g and u == h) ok[v] = 1;
                    if (v == h and u == g) ok[v] = 1;
                    pq.push({-dist[v], v});
                    continue;
                }

                if (dist[v] == dist[u] + w) {
                    if ((v == g and u == h) or
                        (v == h and u == g) or ok[u]) {
                        ok[v] = ok[u];
                        if (v == g and u == h) ok[v] = 1;
                        if (v == h and u == g) ok[v] = 1;
                        pq.push({-dist[v], v});
                    }
                }
            }
        }

        vector <ll> ans;
        while (t--) {
            scanf("%lld", &x);
            if (ok[x]) ans.pb(x);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
            printf("%lld%c", ans[i], " \n"[i+1==ans.size()]);
    }
    return 0;
}
