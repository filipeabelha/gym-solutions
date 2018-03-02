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
const int N = 5e5+5;

ll gcd (ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int n;
ll x;
vector <ll> v;
set <ll> s, t;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        v.pb(x);
    }

    s.insert(v[0]);
    t.insert(v[0]);

    for (int i = 1; i < n; i++) {
        set <ll> r;
        r.insert(v[i]); t.insert(v[i]);
        for (auto e : s) r.insert(gcd(e, v[i])), t.insert(gcd(e, v[i]));
        s = r;
    }

    ll ans = t.size();
    printf("%lld\n", ans);

    return 0;
}
