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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int n, m, p[N], ind[N], no[N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        ind[p[i]] = i;
    }

    cl(no, 63);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = ind[a];
        b = ind[b];
        if (a > b) swap(a, b);
        no[a] = min(no[a], b);
    }

    for (int i = n; i >= 1; i--) no[i] = min(no[i], no[i+1]);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int x = no[i] < INF ? no[i] : n+1;
        ans += x-i;
    }

    printf("%lld\n", ans);

    return 0;
}
