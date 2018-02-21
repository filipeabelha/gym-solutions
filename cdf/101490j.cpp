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
const int N = 1e2+5;

ll n;

struct point {
    ll x, y;
};

ll dis (point a, point b) {
    return abs(a.x-b.x) + abs(a.y-b.y);
}

point s[N], t[N];

bool slv (ll k) {
    set <ll> adj[N];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (dis(s[i], t[j]) <= k) adj[i].insert(j);
        }

    for (int i = 0; i < n; i++) {
        sort(adj+i, adj+n, [](set <ll> a, set <ll> b) { return a.size() < b.size(); });
        if (!adj[i].size()) return false;
        ll el = *(adj[i].begin());
        for (int j = i+1; j < n; j++) if (adj[j].count(el)) adj[j].erase(el);
    }

    return true;
}

int main () {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &s[i].x, &s[i].y);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &t[i].x, &t[i].y);
    }

    ll l = 0, m, r = INF;
    while (l < r) {
        m = (l+r)/2;
        if (!slv(m)) l = m+1;
        else r = m;
    }
    printf("%lld\n", l);
    return 0;
}
