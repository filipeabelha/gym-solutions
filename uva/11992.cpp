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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll st[4*N][3], ladd[4*N], lset[4*N];

void push (int p, int l, int r) {
    if (ladd[p]) {
        st[p][0] += (r-l+1)*ladd[p];
        st[p][1] += ladd[p];
        st[p][2] += ladd[p];
        if (l != r) {
            if (!lset[2*p])   ladd[2*p] += ladd[p];
            else              lset[2*p] += ladd[p];

            if (!lset[2*p+1]) ladd[2*p+1] += ladd[p];
            else              lset[2*p+1] += ladd[p];
        }
        ladd[p] = 0;
    }
    if (lset[p]) {
        st[p][0] = (r-l+1)*lset[p];
        st[p][1] = lset[p];
        st[p][2] = lset[p];
        if (l != r) {
            lset[2*p] = lset[2*p+1] = lset[p];
            ladd[2*p] = ladd[2*p+1] = 0;
        }
        lset[p] = 0;
    }
}

void update (int p, int l, int r, int i, int j, int k, int o) {
    push(p, l, r);
    if (j < l or r < i) return;
    if (i <= l and r <= j) {
        if (o == 1) ladd[p] = k;
        else        lset[p] = k;
        push(p, l, r);
        return;
    }

    update(2*p, l, (l+r)/2, i, j, k, o);
    update(2*p+1, (l+r)/2+1, r, i, j, k, o);

    st[p][0] = st[2*p][0] + st[2*p+1][0];
    st[p][1] = min(st[2*p][1], st[2*p+1][1]);
    st[p][2] = max(st[2*p][2], st[2*p+1][2]);
}

plll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {0, {LINF, -LINF}};
    push(p, l, r);
    if (i <= l and r <= j) return {st[p][0], {st[p][1], st[p][2]}};

    plll u = query(2*p, l, (l+r)/2, i, j);
    plll v = query(2*p+1, (l+r)/2+1, r, i, j);

    return {u.st + v.st, {min(u.nd.st, v.nd.st), max(u.nd.nd, v.nd.nd)}};
}

ll n, m, q, o, k;

struct point {ll x, y;} a, b;

int main () {
    while (~scanf("%lld%lld%lld", &n, &m, &q)) {
        cl(st, 0);
        cl(ladd, 0);
        cl(lset, 0);
        while (q--) {
            scanf("%lld%lld%lld%lld%lld", &o, &a.y, &a.x, &b.y, &b.x);
            if (o < 3) {
                scanf("%lld", &k);
                for (int i = min(a.y, b.y); i <= max(a.y, b.y); i++) {
                    int l = min(a.x, b.x) + m*(i-1);
                    int r = max(a.x, b.x) + m*(i-1);
                    update(1, 1, n*m, l, r, k, o);
                }
            } else {
                plll ans = {0, {LINF, -LINF}};
                for (int i = min(a.y, b.y); i <= max(a.y, b.y); i++) {
                    int l = min(a.x, b.x) + m*(i-1);
                    int r = max(a.x, b.x) + m*(i-1);
                    plll p = query(1, 1, n*m, l, r);
                    ans.st += p.st;
                    ans.nd.st = min(ans.nd.st, p.nd.st);
                    ans.nd.nd = max(ans.nd.nd, p.nd.nd);
                }
                printf("%lld %lld %lld\n", ans.st, ans.nd.st, ans.nd.nd);
            }
        }
    }
    return 0;
}
