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
const int N = 1e7+5;

int t, n, x, v[N], bit[N];
ll ans;

void add (int p) { for (p += 2; p < N; p += p&-p) bit[p]++; }

ll query (int p) {
    if (p < 0) return 0;
    ll r = 0;
    for (p += 2; p; p -= p&-p) r += bit[p];
    return r;
}

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans = 0;
        cl(bit, 0);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        for (int i = n-1; i >= 0; i--) {
            ans += query(v[i]-1);
            add(v[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
