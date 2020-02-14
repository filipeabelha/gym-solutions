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

vector <pii> adj[N];
int dist[N];
priority_queue <pii> pq;

int main () {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) adj[i].clear();

        int n, k;
        scanf("%d%d", &n, &k);
        while (k--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a].pb({b, c});
        }

        int a, b;
        scanf("%d%d", &a, &b);
        cl(dist, 63);
        dist[a] = 0;
        pq.push({0, a});

        while (pq.size()) {
            int ud = -pq.top().st;
            int u = pq.top().nd;
            pq.pop();

            if (dist[u] < ud) continue;

            for (auto p : adj[u]) {
                int v = p.st;
                int w = p.nd;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        if (dist[b] < INF) printf("%d\n", dist[b]);
        else printf("NO\n");

    }

    return 0;
}
