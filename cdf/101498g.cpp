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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;

ll gcd (ll a, ll b) {return (b ? gcd(b, a%b) : a);}
ll lcm (ll a, ll b) {
    ll g = gcd(a, b);
    return (a/g > LINF/b ? LINF : a*(b/g));
}

ll n, m, v[N], ans, s, l;

int main () {
    scanf("%lld", &n);
    while (n--) {
        ans = 0;
        scanf("%lld", &m);

        for (int i = 1; i <= m; i++) scanf("%lld", &v[i]), ans++;

        for (int i = 1; i <= m; i++) {
            s = l = v[i];
            for (int j = i+1; j <= m; j++) {
                if ((l = lcm(l, v[j])) > 1e13) break;
                s += v[j];
                if (!(s%l)) ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
