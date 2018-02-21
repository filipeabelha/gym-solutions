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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 12e5+5;

ll c, p, x, l, a, b;

vi adj[N];
int vis[N];
int cnt[N];
int cur[N];

queue <int> q;

int main () {
    scanf("%lld%lld%lld%lld", &c, &p, &x, &l);
    for (int i = 1; i <= p; i++) {
        scanf("%lld%lld", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        cnt[a]++;
        cnt[b]++;
    }

    q.push(l);

    while (q.size()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : adj[u]) {
            cur[v]++;
            if (2*cur[v] >= cnt[v]) q.push(v);
        }
    }

    printf("%s\n", vis[x] ? "leave" : "stay");
    return 0;
}
