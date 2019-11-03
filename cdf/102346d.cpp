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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k, p, s[N];
vi ch[N], ans;

void dfs (int v) {
    s[v] = 1;
    int mx = 0;
    int ok = 0;
    for (auto u : ch[v]) {
        dfs(u);
        mx = max(mx, s[u]);
    }
    s[v] = mx+1;
    for (auto u : ch[v]) {
        if (s[u] == mx and !ok) ok = 1;
        else ans.pb(s[u]);
    }
}

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p);
        ch[p].pb(i);
    }
    dfs(1);
    ans.pb(s[1]);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    int sum = 0;
    for (int i = 0; i < k; i++) sum += ans[i];

    printf("%d\n", sum);

    return 0;
}
