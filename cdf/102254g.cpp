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

plll s[4*N];
ll v[N];

void build (int p, int l, int r) {
    if (l == r) {s[p] = {v[l], {v[l], v[l]}}; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    s[p] = {s[2*p].st + s[2*p+1].st,
            {min(s[2*p].nd.st, s[2*p+1].nd.st),
             max(s[2*p].nd.nd, s[2*p+1].nd.nd)}};
}

plll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {0, {LINF, -LINF}};
    if (i <= l and r <= j) return s[p];
    plll x = query(2*p, l, (l+r)/2, i, j);
    plll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return {x.st+y.st, {min(x.nd.st, y.nd.st),
                        max(x.nd.nd, y.nd.nd)}};
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {s[p] = {v, {v, v}}; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) {
        s[p] = {s[2*p].st + s[2*p+1].st,
                {min(s[2*p].nd.st, s[2*p+1].nd.st),
                 max(s[2*p].nd.nd, s[2*p+1].nd.nd)}};
    }
}

ll n, q;

int main () {
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    build(1, 1, n);
    while (q--) {
        ll t, a, b;
        scanf("%lld%lld%lld", &t, &a, &b);
        if (t == 1) {
            plll p = query(1, 1, n, a, b);
            printf("%lld\n", p.st - p.nd.st - p.nd.nd);
        } else update(1, 1, n, a, b);
    }

    return 0;
}
