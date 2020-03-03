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
const int N = 2e5+5;

ll n, m, ans = 1;
vl u, v;

int main () {
    scanf("%lld%lld", &n, &m);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    u = v;
    for (auto& x : v) x %= m;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1]) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < i; j++) {
            ans = ans*abs(u[i]-u[j]);
            ans %= m;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
