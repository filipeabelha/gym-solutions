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
const int N = 5e5+5;

ll n, p[N], la[N], lb[N], ra[N], rb[N];
char sc[N];
string s;

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
    scanf("%s", sc);
    s = sc;

    for (int i = 1; i <= n; i++) {
        la[i] = la[i-1];
        lb[i] = lb[i-1];

        if (s[i-1] == 'A') la[i] += p[i];
        else               lb[i] += p[i];
    }

    for (int i = n; i >= 1; i--) {
        ra[i] = ra[i+1];
        rb[i] = rb[i+1];

        if (s[i-1] == 'A') ra[i] += p[i];
        else               rb[i] += p[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, la[i] + rb[i]);
        ans = max(ans, lb[i] + ra[i]);
    }

    printf("%lld\n", ans);


    return 0;
}
