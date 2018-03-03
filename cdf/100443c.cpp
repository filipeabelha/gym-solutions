#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;


const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ld ONE = 1.0;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct point {
    ll x, y, f;
};

bool wa[N][N], st[N][N], li[N][N], es[N][N], ok[N][N];
ll ori[N];
ld dist[N];

vector <point> pts;
priority_queue <pll> pq;
vector <ll> ans;
int n, m, q;

ld dis (ll i, ll j) {
    point a = pts[i];
    point b = pts[j];
    return sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y)+25*abs(a.f-b.f)*abs(a.f-b.f));
}

void dijkstra (ll strt) {
    for (int i = 0; i < pts.size(); i++) dist[i] = INF;
    cl(ok, 0);
    dist[strt] = 0;
    pq.push(mp(0, strt));
    while (pq.size()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (int v = 0; v < pts.size(); v++) {
            if (v == u) continue;
            ld w = INF;
            if (wa[v][u] or wa[u][v] or st[v][u] or st[u][v]) w = min(w, dis(u, v));
            else if (es[u][v])                                w = min(w, ONE);
            else if (es[v][u])                                w = min(w, 3*dis(u, v));
            else if (li[u][v] or li[v][u])                    w = min(w, ONE);

            if (ge(dist[v], dist[u] + w)) {
                dist[v] = dist[u] + w;
                ori[v] = u;
                pq.push(mp(-dist[v], v));
            }
        }
    }
}

void go (int b, int a) {
    ans.pb(b);
    if (b == a) return;
    go(ori[b], a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        point a;
        cin >> a.f >> a.x >> a.y;
        pts.pb(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s[0] == 'w') wa[a][b] = true;
        if (s[0] == 's') st[a][b] = true;
        if (s[0] == 'l') li[a][b] = true;
        if (s[0] == 'e') es[a][b] = true;
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        cl(ori, -1);
        dijkstra(a);
        ans.clear();
        go(b, a);
        reverse(ans.begin(), ans.end());
        for (auto x : ans) printf("%lld ", x); printf("\n");
    }
    return 0;
}
