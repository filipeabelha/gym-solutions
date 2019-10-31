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

priority_queue <pll> pq[N];
set <ll> bydist[N];
vi adj[N];
ll n, k, m, mx;

int main () {
    scanf("%lld%lld", &n, &k);

    for (int v = 1; v <= n; v++) {
        ll x;
        scanf("%lld", &x);
        bydist[x].insert(v);
        mx = max(mx, x);
    }

    if (bydist[0].size() != 1) {
        printf("-1\n");
        return 0;
    }

    for (auto v : bydist[0]) pq[0].push({0, v});

    for (int x = 1; x <= mx; x++) {
        for (auto v : bydist[x]) {
            if (pq[x-1].empty() or -pq[x-1].top().st >= k) {
                printf("-1\n");
                return 0;
            }
            pll p = pq[x-1].top(); pq[x-1].pop();
            ll deg = -p.st; deg++;
            ll u = p.nd;
            pq[x-1].push({-deg, u});
            pq[x].push({-1, v});
            m++;
            adj[u].pb(v);
        }
    }

    printf("%lld\n", m);
    for (int i = 0; i < N; i++)
        for (auto x : adj[i])
            printf("%d %d\n", i, x);

    return 0;
}
