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
const int N = 2e5+5;

ll n, q, a, b, v[N];
pll u[N];
vector <pll> qry;

int main () {
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    for (int i = 0; i < N; i++) u[i].nd = i;
    while (q--) {
        scanf("%lld%lld", &a, &b);
        u[a].st++;
        u[b+1].st--;
        qry.pb({a, b});
    }
    for (int i = 1; i < N; i++) u[i].st += u[i-1].st;

    sort(u+1, u+n+1);
    sort(v+1, v+n+1);

    for (int i = 0; i <= n; i++) u[i].st = v[i], swap(u[i].st, u[i].nd);
    sort(u+1, u+n+1);
    for (int i = 0; i <= n; i++) v[i] = u[i].nd;
    for (int i = 1; i <= n; i++) v[i] += v[i-1];

    ll ans = 0;
    for (auto p : qry)
        ans += v[p.nd] - v[p.st-1];

    printf("%lld\n", ans);

    return 0;
}
