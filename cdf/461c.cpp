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
const int N = 1e7+5;

int n, q, o, x, y;
ll s, t, bit[N];
bool inv;

void add (ll p, int v) { for (p += 2; p < N; p += p&-p) bit[p] += v; }

ll query (ll p) {
    ll r = 0;
    for (p += 2; p; p -= p&-p) r += bit[p];
    return r;
}

ll qry (int i, int j) {
    return query(j) - (i > 0 ? query(i-1) : 0);
}

int main () {
    scanf("%d%d", &n, &q);
    t = n;
    for (int i = 0; i < n; i++) add(i, 1);
    while (q--) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%d", &x);
            if (inv) {
                x += s;
                x = t-x;
            }
            if (2*x <= t-s) {
                for (int i = 1; i <= x; i++) {
                    ll v = qry(s+x-i, s+x-i);
                    add(s+x+i-1, v);
                    add(s+x-i, -v);
                }
                s += x;
                if (inv) inv ^= 1;
            } else {
                x += s;
                x = t-x;
                for (int i = 1; i <= x; i++) {
                    ll v = qry(t-x+i-1, t-x+i-1);
                    add(t-x-i, v);
                    add(t-x+i-1, -v);
                }
                t -= x;
                if (!inv) inv ^= 1;
            }
        } else {
            scanf("%d%d", &x, &y);
            if (inv) {
                x += s;  y += s;
                x = t-x; y = t-y;
                swap(x, y);
            }
            printf("%lld\n", qry(s+x, s+y-1));
        }
    }
    return 0;
}
