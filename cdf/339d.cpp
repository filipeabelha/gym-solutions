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
const int N = 2e5+5;

pii st[4*N];
int v[N];

void build (int p, int l, int r) {
    if (l == r) { st[p] = {v[l], 0}; return; }

    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);

    if (!st[2*p].nd) st[p] = {st[2*p].st | st[2*p+1].st, 1};
    else             st[p] = {st[2*p].st ^ st[2*p+1].st, 0};
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) { st[p] = {v, 0}; return; }

    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);

    if (!st[2*p].nd) st[p] = {st[2*p].st | st[2*p+1].st, 1};
    else             st[p] = {st[2*p].st ^ st[2*p+1].st, 0};
}

int n, q, a, b;

int main () {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= (1 << n); i++) scanf("%d", &v[i]);

    build(1, 1, (1 << n));

    while (q--) {
        scanf("%d%d", &a, &b);
        update(1, 1, (1 << n), a, b);
        printf("%d\n", st[1].st);
    }

    return 0;
}
