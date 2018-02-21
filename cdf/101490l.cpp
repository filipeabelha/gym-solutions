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
const int N = 2e4+5;

ll n, v[N], ans;

bool checkTriangle (ll a, ll b, ll c) {
    if (a >= b+c) return false;
    if (b >= a+c) return false;
    if (c >= a+b) return false;
    return true;
}

int main () {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
    sort(v, v+n);
    for (int i = 2; i < n; i++) if (checkTriangle(v[i-2], v[i-1], v[i])) ans = 1;
    printf("%s\n", ans ? "possible" : "impossible");
    return 0;
}
