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
const int N = 2e5+5;

typedef long long type;
struct line { type b, m; };

int nh, pos;
line hull[N];

bool check(line s, line t, line u) {
    return (s.b - t.b)*(u.m - s.m) < (s.b - u.b)*(t.m - s.m);
}

void update (line s) {
    if (nh == 1 and hull[nh-1].b == s.b) nh--;
    if (nh > 0  and hull[nh-1].m >= s.m) return;
    while (nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) nh--;
    pos = min(pos, nh);
    hull[nh++] = s;
}

type eval (int id, type x) { return hull[id].b + hull[id].m * x; }

type query (type x) {
    while (pos+1 < nh and eval(pos, x) < eval(pos+1, x)) pos++;
    return eval(pos, x);
}

ll n, c, h[N], dp[N];

int main () {
    scanf("%lld%lld", &n, &c);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
        ll q = -query(h[i]) + h[i]*h[i];
        if (i > 0) dp[i] = -query(h[i]) + h[i]*h[i];

        line l;
        l.b = -(h[i]*h[i] + c + dp[i]);
        l.m = -(-2*h[i]);
        update(l);
    }

    printf("%lld\n", dp[n-1]);

    return 0;
}
