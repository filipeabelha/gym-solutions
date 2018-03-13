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
const int N = 1e5+5;

ll n, m, k;

bool slv (ll h) {
    ll u = h;

    ll a = k-1;
    ll b = n-k;

    if (a > h-1) u += (h-1)*h/2;
    else u += (h-1+h-a)*a/2;

    if (b > h-1) u += (h-1)*h/2;
    else u += (h-1+h-b)*b/2;

    return u <= m;
}

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);
    m -= n;
    int l = 0, h, r = m;
    while (l < r) {
        h = (l+r+1)/2;
        if (!slv(h)) r = h-1;
        else l = h;
    }
    printf("%d\n", l+1);
    return 0;
}
