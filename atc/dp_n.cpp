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
typedef vector<ll> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 4e2+5;

ll n, t, a[N], s[N];
ll memo[N][N];

ll sum (int l, int r) {
    return s[r] - s[l-1];
}

ll cost (int l, int r) {
    if (memo[l][r]) return memo[l][r];
    if (l == r) return memo[l][r] = 0;
    ll ans = LINF;
    for (int i = l; i < r; i++) {
        ans = min(ans, sum(l, i) + sum(i+1, r) + cost(l, i) + cost(i+1, r));
    }
    return memo[l][r] = ans;
}

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = a[i];
        s[i] += s[i-1];
    }

    printf("%lld\n", cost(1, n));

    return 0;
}