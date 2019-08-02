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
const int N = 800+5;

ll n, m, k, u, v, w, dist[N][N], cnt;
vector <plll> edges;
map <ll, ll> id;

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        edges.pb({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = LINF;

    for (int i = 0; i < min(k, m); i++) {
        plll p = edges[i];

        ll u = p.nd.st;
        ll v = p.nd.nd;

        if (!id[u]) id[u] = ++cnt;
        if (!id[v]) id[v] = ++cnt;
    }

    for (auto p : edges) {
        ll w = p.st;
        ll u = p.nd.st;
        ll v = p.nd.nd;

        if (id[u] and id[v]) {
            dist[id[u]][id[v]] = w;
            dist[id[v]][id[u]] = w;
        }
    }

    for (int i = 0; i < N; i++) dist[i][i] = 0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    vector <ll> ans;
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            ans.pb(dist[i][j]);

    sort(ans.begin(), ans.end());

    if (k-1 < ans.size()) printf("%lld\n", ans[k-1]);
    else printf("foo\n");
    return 0;
}
