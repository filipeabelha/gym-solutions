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
typedef pair<pll, ll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k;
ll v[N];
pll p[N], q[N];
map <ll, ll> ans;

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].st);
        q[i].st = p[i].st;
        v[i] = p[i].st;
    }

    sort(v+1, v+1+n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].nd);
        q[i].nd = p[i].nd;
    }
    sort(p+1, p+1+n);

    ll sum = 0;
    multiset <ll> m;
    for (int i = 1; i <= n; i++) {
        sum += p[i].nd;
        m.insert(p[i].nd);

        while (m.size() > k) {
            sum -= *m.begin();
            m.erase(m.find(*m.begin()));
        }

        ans[p[i].st] = sum;
    }

    for (int i = 1; i <= n; i++) {
        ll x = *(lower_bound(v+1, v+1+n, q[i].st) - 1);
        printf("%lld%c", ans[x] + q[i].nd, " \n"[i==n]);
    }
    return 0;
}
