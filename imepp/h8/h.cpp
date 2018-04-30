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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e6+5;

ll bit[N][2], n, k, a, b;
char c;

void add (ll j, ll p, ll x) {
    for (p += 2; p < N; p += p&-p) bit[p][j] += x;
}

ll query (ll j, ll p) {
    ll ans = 0;
    for (p += 2; p; p -= p&-p) ans += bit[p][j];
    return ans;
}

ll qry (ll j, ll a, ll b) {
    return query(j, b) - query(j, a-1);
}

int main () {
    while (~scanf("%lld%lld", &n, &k)) {
        cl(bit, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a);
            if (a <  0) add(0, i, 1);
            if (a == 0) add(1, i, 1);
        }
        while (k--) {
            scanf(" %c %lld %lld", &c, &a, &b);
            if (c == 'C') {
                add(0, a, -qry(0, a, a));
                add(1, a, -qry(1, a, a));
                if (b <  0) add(0, a, 1);
                if (b == 0) add(1, a, 1);
            }
            if (c == 'P') {
                if (qry(1, a, b) > 0) {
                    printf("0");
                    continue;
                }
                printf("%c", qry(0, a, b)&1 ? '-' : '+');
            }
        }
        printf("\n");
    }
    return 0;
}
