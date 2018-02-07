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
const int N = 1e2+5;


ll gcd (ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm (ll a, ll b) { return a*b/gcd(a, b); }

int n, ans = 1, v[N];

void go (int targ, int where, int dep) {
    if (where == targ) {
        ans = lcm(ans, dep);
        return;
    }
    go(targ, v[where], dep+1);
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) go(i, v[i], 1);
    printf("%d\n", ans);
    return 0;
}
